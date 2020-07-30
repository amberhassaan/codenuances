#include <allocator>
#include <iostream>
#include <type_traits>
#include <vector>
#include <utility>

template <typename In, size_t Index, typename Arg0, typename... Args> 
struct GetTypeID {
  constexpr static const size_t value = std::is_same<In, Arg0> ? Index : GetTypeID<In, Index + 1, Args...>;
}

template <typename... Args>
struct TaggedPtr {
  using GenericPtr = std::uint64_t;

  GenericPtr mPtr;

  constexpr static const size_t MAX_TYPES = 8ul;

  static_assert(sizeof...(Args) <= MAX_TYPES, "Can't uniquely encode types");

  template <typename T>
  TaggedPtr(T* ptr): mPtr(reinterpret_cast<GenericPtr>(ptr)) noexcept {

    constexpr size_t ID = GetTypeID<T, 0, Args...>::value;
    mPtr |= ID;
  }

  size_t id() const noexcept {
    return mPtr & (MAX_TYPES - 1);
  }

  template <typename T> 
  T* ptr() noexcept {
    return reinterpret_cast<T*>(mPtr & ~(MAX_TYPES - 1));
  }

  template <typename... Funcs>
  void applyByType(Funcs&&... funcs) {
    static_assert(sizeof...(Funcs) == sizeof...(Args), "mismatch in number of func objs and types");

    auto ID = id();
    int arr[] = { (0, (ID == IntSeq) ? funcs(*ptr<Args>()) : 0)... };
  }

};

template <typename... Args>
struct TaggedPtrContainer {

  using TPtr = TaggedPtr<Args...>;

  using AllocTuple = std::tuple<std::allocator<Args>...>;

  AllocTuple mAllocs;

  using Container = std::vector<TPtr>;
  Container mContainer;

  template <typename E>
  push(const E& elem) {
    static_assert(HasTypeInParams<E, Args...>::value, "invalid type");
    constexpr size_t ID = GetTypeID<E, 0, Args...>::value;
    auto& alloc = std::get<ID>(mAllocs);
    E* ptr = alloc.allocate(1);
    using AllocTraits = std::allocator_traits<decltype(alloc)>;
    AllocTraits::construct(alloc, ptr, elem);

    TPtr tptr(ptr);
    mContainer.emplace_back(ptr);
  }

  template <size_t ID>
  void destroyOne(TPtr& tptr) {
    auto& alloc = std::get<ID>(mAllocs);

    using T = typename std::tuple_element<ID, Args...>::type;
    T* ptr = tptr.ptr<T>();

    using AllocTraits = std::allocator_traits<decltype(alloc)>;
    AllocTraits::destruct(alloc, ptr);
    AllocTraits::deallocate(alloc, ptr, 1);

  }

  void destroyAllElems() noexcept {
    for (TPtr& tptr: mContainer) {
      int arr[] = { (0, ((ID == IntSeq) ? destroyOne<IntSeq>(tptr) : 0)... };
    }
  }

  ~TaggedPtrContainer() noexcept {
    destroyAllElems();
  }

};




int main() {

  return 0;
}

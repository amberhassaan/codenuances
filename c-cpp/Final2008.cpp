/*
 * Question 1
 * Array<T, int size = 128>
 * for 128 or lesser create array of 128 on stack else allocate on heap
 *
 * Question 2
 * if sizeof(Y) > sizeof(X), then Ansertype is Y else Ansertype is X
 *
 * Question 3
 *
 * class Foo { char x }
 *
 * Foo a, Foo b, Foo c;
 * cout << a << b << c << endl; should pring cba
 * use Expression templates
 *
 * Question 4
 * Ptr<T> is a reference counting pointer
 *
 *
 * Question 5
 * write a program using Ptr<int> that creates garbage, but don't
 * call new or delete in your program
 *
 *
 * Question 6
 * class Base {
 * }
 * class Deirved {
 *  int* x;
 *  x = new int;
 * }
 * Base* b
 * if( random()%2 == 0 ) {
 *    b = new Base[5];
 * }
 * else {
 *    b = new Derived[5];
 * }
 * how to delete b,
 *
 *
 * Question 7
 * a) why member template functions cannot be virtual
 * b) if a virtual fuction has 
 *    return type T in Base
 *    return type S in Derived
 *    what is the relationship between T and S ( are they same)
 * c) if a virtual function has
 *    argument type T in Base
 *    argument type S in Derived
 *    what is the relationship between T and S ( are they same)
 *    
 * d)
 * int* array[N]
 *
 * if( random() condition ) {
 *    array[ k % N ] = new int;
 * }
 *
 * when will be a copy based garbage collector better than a 
 * mark-sweep garbage collector.
 *

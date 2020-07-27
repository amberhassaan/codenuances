#include <iostream>
#include <string>
#include <sstream>
#define DB(s) std::cout << #s << " = " << (s) << std::endl;

using namespace std;

/*
 * once virtual is always virtual
 *
 * destructors should be virtual so that the proper destructor is called 
 *
 * non-virtual inheritance: base ptr can point to a derived object but calling a method will result in the base version of the method,
 *
 * const and non-const versions are overloaded on each other, the signature of virtual function should be same in 
 * base and derived ( including constness )  in order to call the correct derived version. Try making Hen::name non-const
 *
 * The signature and return type both should be the same for virtual functions. Changing return type gives an error
 *
 * If signature is changed, then overriding does not happen, and base version of function is called
 *
 * Downcasting, using dynamic_cast, from Bird* to Crow* or Hen*
 *    dynamic_cast returns 0 if it fails
 *    compares the addresses of VFTs of two classes internally
 *
 */
struct Bird {

   int legs;

   Bird() {
      cout << this << " Bird created " << endl;
      legs = 2;
   }
   virtual string name() const {
      return "Just a normal Bird";
   }
   virtual void fly()=0;

   int numWings() {
      return 2;
   }

   virtual ~Bird() {
      cout << this << " Bird died " << endl;
   }

   virtual bool operator == (const Bird& that ) const {
      DB( name() );
      DB( that.name() );
      return ( name() == that.name() );
   }
};


struct Hen: public Bird {
   int eggs;

   Hen() {
      cout << this << " Hen created " << endl;
      eggs = 12;
   }

   virtual string name() const {
      return " I am Hen "; 
   }

   virtual void fly() {
      cout << this << " I am a Hen, I can't fly" << endl;
   }

   virtual void layEggs() {
      cout << this << " Hen layed eggs = " << eggs << endl;
   }

   virtual ~Hen() {
      cout << this << " Hen destroyed " << endl;
   }
};


struct Crow: public Bird {

   int legs;

   Crow() {
      cout << this << " Crow created " << endl;
      legs = 34;
   }

   virtual string name() const {
      stringstream s;
      s << this << " I am a Crow , legs = " <<  legs << endl;
      return s.str();
   }

   virtual void fly() {
      cout << this << " A crow can fly " << endl;
   }

   virtual ~Crow() {
      cout << this << " Crow destroyed " << endl;
   }
};

int main() {
   // Bird b; // compile error, fly is a pure virtual function

   DB(sizeof(Hen));
   DB( sizeof(Bird));

   Bird* b;

   DB( sizeof(b) );
   b = new Hen();  

   DB( sizeof( *b ) ); // == 4 // Hen part is trucated

   DB( sizeof( * dynamic_cast<Hen*>(b) )  );

   // b->layEggs();

   int* obj = reinterpret_cast<int*>(b);
   int* vftptr = reinterpret_cast<int*>(*obj);

   DB( *vftptr );
   DB( *(vftptr+4) );
   DB( *(vftptr+8) );

   cout << "With virtual binding"  << b->name() << endl;

   cout << "With explicit base:: resolution" << b->Bird::name () << endl;

   b->fly();

   // b->Bird::fly (); // generates compile time error



   DB(b);

   Bird* c = new Crow();

   DB( c->legs ); // returns 2;
   DB( dynamic_cast<Crow*>(c)->legs );
   DB( dynamic_cast<Hen*>(c) );

   c->fly();
   DB( c->name() );

   Bird& hen = *b;

   DB( hen.name() );

   hen.fly();

   DB( hen == *c );

   DB( c->operator==(hen) );

   delete b;
   delete c;
}

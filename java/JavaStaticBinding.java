abstract class Base {

  void foo () { 
    System.out.println ("Base::foo");
  }

  abstract void bar ();
}

class Derived extends Base{

  void foo () {
    System.out.println ("Derived::foo");
  }

  void bar () {
    super.foo ();
    System.out.println ("Derived::bar");
  }
}



public class JavaStaticBinding {

  public static void main (String[] args) {

    Base d0 = (Base) new Derived (); 


    Derived d1 = new Derived ();


    d0.foo ();
    ((Base) d1).foo ();

    d1.bar ();

  }
}

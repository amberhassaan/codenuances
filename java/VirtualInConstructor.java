public class VirtualInConstructor {

  static class Base {

    public Base () {
      foo ();
    }

    public void foo () {
      System.out.println ("I am in Base");
    }
  }

  static class Derived extends Base {

    Integer x = 42; //  = null;

    public Derived () {
      super ();
      x = new Integer (32);
    }

    public void foo () {
      System.out.println ("I am in Derived");
      System.out.println (" x + 42 is: " + (x + 42));
    }
  }

  public static void main (String[] args) {

    Base b = new Base ();

    Derived d0 = new Derived ();

    Base d1 = new Derived ();
  }

}

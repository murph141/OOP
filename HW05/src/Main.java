public class Main {

   public static void main(String[] args) {

      B b = new B( );
      D1 d1 = new D1( );
      D2 d2 = new D2( );

      System.out.println("Base and b calls");
      B.f1( ); 
      //B.f2( ); Private method in the B class
      B.f1( ); // Should be accessed statically (like above)
      //b.f2( ); Private method in the B class
      b.f3( ); 
      //b.f4( ); Private method in the B class
      //b.f5( ); Not a method in B
      b.bCaller( );
      System.out.println(" ");

      System.out.println("D1 and d1 calls");
      D1.f1( ); 
      //D1.f2( ); Private method from the B class
      D1.f1( ); // Should be accessed statically (like above)
      //d1.f2( ); Private method from the B class
      d1.f3( ); 
      //d1.f4( ); Private method from the D1 class
      d1.f5( ); 
      //d1.f6( ); Private method from the D1 class
      //d1.f7( ); Not a method in D1 or B
      d1.d1Caller( );
      System.out.println(" ");
     
      System.out.println("d1.bCaller");
      d1.bCaller( );
      System.out.println(" ");

      System.out.println("D2 and d2 calls");
      D2.f1( ); 
      //D2.f2( ); Private method from the B class
      d2.f1( ); // Should be accessed statically (like above)
      //d2.f2( ); Private method from the B class
      d2.f3( ); 
      //d2.f4( ); Private method from the D2 class
      d2.f5( ); 
      //d2.f6( ); Private method from the D1 class
      d2.f7( ); 
      d2.d2Caller( );
      System.out.println(" ");
    }
}


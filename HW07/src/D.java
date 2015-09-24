public class D extends B {

	void foo() {
	      System.out.println("B:foo()");
	}
	
   void foo(float f) {
      System.out.println("B:foo(float)");
   }

   void foo(int i, B b, float f) {
      System.out.println("B:foo(int, B, float)");
   }

   void foo(short s, B b, float f) {
      System.out.println("B:foo(short, B, float)");
   }

   void foo(char c, D d) {
      System.out.println("B:foo(char, D)");
   }
   
   void foo(D d, float f) {
	      System.out.println("B:foo(D, float)");
	      }
   
   void foo(char c, D d, double df) {
	      System.out.println("B:foo(char, D, double)");
	   }
   
   void foo(int i, D d, double df) {
	      System.out.println("B:foo(int, D, double)");
	   }
   
   void foo(int i, D d) {
	      System.out.println("B:foo(int, D)");
	   }

   void foo(short s, double d) {
      System.out.println("B:foo(short, double)");
   }

   void foo(short s, B b) {
      System.out.println("B:foo(short, B)");
   }
}

package hw6PolyJava;
import java.io.*;

public class Main {

   public static void main(String args[]) {
      C0 c01 = new C0( );
      C0 c02 = new C0(1,2);
      C1 c11 = new C1( );
      C1 c12 = new C1(3, 4, 5.0f);

      System.out.println("c01.a.intValue( ): " + c01.a.intValue( )); // Prints a from C0 (0)
      System.out.println("c01.b.intValue( ): " + c01.b.intValue( )); // Prints b from C0 (0)
      System.out.println("c01.x: " + c01.x); // Prints x from C0 (0)
      System.out.println("c01.y: " + c01.y); // Prints y from C0 (0)

      System.out.println("c02.a.intValue( ): " + c02.a.intValue( )); // Prints a from C0 (1)
      System.out.println("c02.b.intValue( ): " + c02.b.intValue( )); // Prints b from C0 (2)
      System.out.println("c02.x: " + c02.x); // Prints x from C0 (1)
      System.out.println("c02.y: " + c02.y); // Prints y from C0 (2)

      System.out.println("c11.a.intValue( ): " + c11.a.intValue( )); // Prints a from C1 (0)
      System.out.println("c11.b.intValue( ): " + c11.b.intValue( )); // Prints b from C1 (0)
      System.out.println("c11.c.floatValue( ): " + c11.c.floatValue( )); // Prints c from C1 (1.5)
      System.out.println("c11.x: " + c11.x); // Prints x from C1 (0)
      System.out.println("c11.y: " + c11.y); // Prints y from C1 (0)
      System.out.println("c11.z: " + c11.z); // Prints z from C1 (1.5)

      c01 = c12;
      System.out.println("c12.a.intValue( ): " + c01.a.intValue( )); // Prints a from C1 (3)
      System.out.println("c12.b.intValue( ): " + c01.b.intValue( )); // Prints b from C1 (4)
      System.out.println("c12.c.floatValue( ): " + ((C1) c01).c.floatValue( )); // Prints c from C1 (5.0)
      System.out.println("c12.x: " + c01.x); // Prints x from C0 (0)
      System.out.println("c12.y: " + c01.y); // Prints y from C0 (0)

      System.out.println("c02.getA( ): " + c02.getA( )); // Prints -a from C0 (-1)
      System.out.println("c02.getB( ): " + c02.getB( )); // Prints -b from C0 (-2)
      System.out.println("c02.getX( ): " + c02.getX( )); // Prints -x from C0 (-1)
      System.out.println("c02.getY( ): " + c02.getY( )); // Prints -y from C0 (-2)

      System.out.println("c12.getA( ): " + c01.getA( )); // Prints -a from C0 (-3)
      System.out.println("c12.getB( ): " + c01.getB( )); // Prints -b from C0 (-4)
      System.out.println("c12.getC( ): " + ((C1) c01).getC( )); // Prints c from C1 (5.0)
      System.out.println("c12.getX( ): " + c01.getX( )); // Prints -x from C0 (0)
      System.out.println("c01.getY( ): " + c01.getY( )); // Prints y + 1 from C1 (1)
      System.out.println("c01.getZ( ): " + c01.getY( )); // Prints y + 1 from C1 (1)
   }
}

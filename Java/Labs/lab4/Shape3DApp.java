package Labs.lab4;

import java.util.Scanner;

import Labs.lab4.Shape.Cuboid;
import Labs.lab4.Shape.Pyramid;
import Labs.lab4.Shape.Sphere;
import java.util.Scanner;


public class Shape3DApp {
    public static void main(String[] args) {
        int radius, base, THeight, RLength, width, RHeight;
        Scanner sc = new Scanner(System.in);
        System.out.println("Input radius for circle: ");
        radius = sc.nextInt();
        System.out.println("Input base for Triangle: ");
        base = sc.nextInt();
        System.out.println("Input height for circle: ");
        THeight = sc.nextInt();
        System.out.println("Input length for Rectangle: ");
        RLength = sc.nextInt();
        System.out.println("Input width for Rectangle: ");
        width = sc.nextInt();
        System.out.println("Input length for Rectangle: ");
        RHeight = sc.nextInt();
        Sphere circle = new Sphere(radius);
        Pyramid triangle = new Pyramid(base, THeight);
        Cuboid rectangle = new Cuboid(width, RLength, RHeight);
        double surfaceArea = circle.surfaceArea() + triangle.surfaceArea() + rectangle.surfaceArea();
        System.out.println(rectangle.surfaceArea());
        System.out.printf("Total Surface Area: %.2f \n",surfaceArea);
    }
}

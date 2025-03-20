package Labs.lab4;

import Labs.lab4.Shape.Cuboid;
import Labs.lab4.Shape.Pyramid;
import Labs.lab4.Shape.Sphere;


public class Shape3DApp {
    public static void main(String[] args) {
        Sphere circle = new Sphere(10);
        Pyramid triangle = new Pyramid(25, 20);
        Cuboid rectangle = new Cuboid(50, 30, 20);
        double surfaceArea = circle.surfaceArea() + triangle.surfaceArea() + rectangle.surfaceArea();
        System.out.println(rectangle.surfaceArea());
        System.out.printf("Total Surface Area: %.2f \n",surfaceArea);
    }
}

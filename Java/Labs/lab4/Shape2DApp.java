package Labs.lab4;

import Labs.lab4.Shape.Circle;
import Labs.lab4.Shape.Rectangle;
import Labs.lab4.Shape.Triangle;
import java.util.Scanner;

public class Shape2DApp {
    public static void main(String[] args) {
        int radius, base, height, length, breadth;
        Scanner sc = new Scanner(System.in);
        System.out.println("Input radius for circle: ");
        radius = sc.nextInt();
        System.out.println("Input base for Triangle: ");
        base = sc.nextInt();
        System.out.println("Input height for circle: ");
        height = sc.nextInt();
        System.out.println("Input length for Rectangle: ");
        length = sc.nextInt();
        System.out.println("Input breadth for Rectangle: ");
        breadth = sc.nextInt();
        Circle circle = new Circle(radius);
        Triangle triangle = new Triangle(base, height);
        Rectangle rectangle = new Rectangle(length, breadth);
        double area = circle.area() + triangle.area() + rectangle.area();
        System.out.println("The area is: "+ area);
    }
}

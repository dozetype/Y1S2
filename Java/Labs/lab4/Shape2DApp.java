package Labs.lab4;

import Labs.lab4.Shape.Circle;
import Labs.lab4.Shape.Rectangle;
import Labs.lab4.Shape.Triangle;

public class Shape2DApp {
    public static void main(String[] args) {
        Circle circle = new Circle(10);
        Triangle triangle = new Triangle(25, 20);
        Rectangle rectangle = new Rectangle(50, 20);
        double area = circle.area() + triangle.area() + rectangle.area();
        System.out.println(area);
    }
}

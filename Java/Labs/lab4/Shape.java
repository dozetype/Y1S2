package Labs.lab4;

public interface Shape {
    public double area();

    class Circle{
        private double radius;

        public Circle(double radius){
            this.radius = radius;
        }
    
        public double area(){
            return Math.PI*radius*radius;
        }
    }

    class Sphere extends Circle{
        public Sphere(double radius){
            super(radius);
        }

        public double surfaceArea(){
            return 4*Math.PI*super.radius*super.radius;
        }
    }
    ////////////////////////////////////////////////////////////////////////
    class Rectangle{
        private double width, length;

        public Rectangle(double width, double length){
            this.width = width;
            this.length = length;
        }
        
        public double area(){
            return width*length;
        }
    }

    class Cuboid extends Rectangle{
        private double height;

        public Cuboid(double width, double length, double height){
            super(width, length);
            this.height = height;
        }
        public double surfaceArea(){
            return 2*(super.width*super.length + super.width*height + height*super.length);
        }
    }
    
    class Cylinder extends Rectangle{
        private double radius;
        public Cylinder(double width, double length, double radius){ //width is extra
            super(width, length);
            this.radius = radius;
        }
        public double surfaceArea(){
            return 2*Math.PI*radius*super.length + 2*Math.PI*radius*radius;
        }
    }
    /////////////////////////////////////////////////////////////////////////////////
    class Triangle{
        private double base, height;
        public Triangle(double base, double height){
            this.base = base;
            this.height = height;
        }
        
        public double area(){
            return 0.5 * this.base * this.height;
        }
    }
    
    class Pyramid extends Triangle{
        public Pyramid(double base, double height){
            super(base, height);
        }
        
        public double surfaceArea(){ //b**2 + 2(b)*sqrt(((a**2)/4) + h**2)
            double base=super.base, height = super.height;
            return (base*base) + (2*base)*Math.sqrt((base*base)/4 + (height*height));
        }
    }
    
    class Cone extends Triangle{
        private double radius;
        public Cone(double base, double height, double radius){ //dk if should add base
            super(base, height);
            this.radius = radius;
        }
        
        public double surfaceArea(){
            double height=super.height; 
            return (Math.PI*radius)*(radius+Math.sqrt(height*height + radius*radius));
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////
    class Square{
        private double x;
        public Square(double x){
            this.x = x;
        }
        
        public double area(){
            return x*x;
        }
    
        public double surfaceArea(){
            return 6*(x*x);
        }
    }
}
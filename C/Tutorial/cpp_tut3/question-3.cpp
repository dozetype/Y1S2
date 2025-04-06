#include <iostream>
#include <string>

class Pen {
private:
    std::string color;
    double price;

public:
    Pen(std::string initialColor, double initialPrice) {
        color = initialColor;
        price = initialPrice;
    }

    Pen& setColor(std::string newColor) {
        // TO-DO: Write your code here
        this->color = newColor;
        return *this; //used for method chaining
    }

    Pen& setPrice(double newPrice) {
        // TO-DO: Write your code here
        this->price = newPrice;
        return *this;
    }

    void display() const {
        // TO-DO: Write your code here
        std::cout << "Pen Color: " << this->color << std::endl;
        std::cout << "Price: $" << this->price << std::endl;
        
    }
};

int main() {
    // Creating a Pen object and using method chaining
    Pen myPen("Blue", 1.5);
    std::cout<< "The original color and price of the pen: " << std::endl;
    myPen.display();
    
    std::cout<< std::endl<<"The color and price of the pen after setting: " << std::endl;
    myPen.setColor("Red") //method chaining
         .setPrice(2.0)
         .display();

    return 0;
}

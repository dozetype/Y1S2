#include <iostream>

double calulateNetForce(double);
double currAirResistance(double);
double currVel(double, double);

constexpr double gravity = 9.81;
constexpr double height = 100;
constexpr double mass = 69;
constexpr double airDensity = 1.225; //general
constexpr double dragCoeff = 1.0; //how aerodynamic the thing is
constexpr double crossSectional = 0.7; //standing flat


double terminalVel = sqrt((2*mass*gravity) / (airDensity*dragCoeff*crossSectional));

//N
double calculateNetForce(const double vel) {
    return mass*gravity - currAirResistance(vel);
}

//N
double currAirResistance(double vel) {
    return 0.5 * airDensity * dragCoeff * crossSectional * pow(vel, 2);
}

double currVel(double time) {
    return terminalVel * tanh( sqrt((0.5 * gravity * airDensity * dragCoeff * crossSectional) / mass) * time);
}

double timeFalling(double height) {
    return terminalVel/gravity * acosh( exp( (gravity*height) / pow(terminalVel, 2) ) );
}

double stoppingDistance = 0.01;
double endingForce(double vel) {
    return 0.5 * mass * pow(vel, 2) / stoppingDistance;
}
int main() {
    // std::cout << "The terminal velocity is: " << terminalVel << "m/s \n\n";
    // std::cout << "Enter what height to jump at: ";
    // double h{};
    // std::cin >> h;
    // std::cout << "The ending velocity when jumping from " << h << ": ";
    // double endingVel = currVel(timeFalling(h));
    // std::cout << endingVel << "m/s \n";
    // std::cout << "The impact force when landing: " << endingForce(endingVel) << "N \n";
    std::cout << "terminal: " << terminalVel << std::endl;
    for (int i=0; i<100; i+=4) {
        double endingVel = currVel(timeFalling(i));
        std::cout << "Height: " << i << "m Ending Vel: " << endingVel << "m/s Force: " << endingForce(endingVel) << "N \n";
    }
}
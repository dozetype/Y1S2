///////// Student Info/////////
//
//           Your Name: Chen Xing Wei
//      Your NTU Email: C240155@e.ntu.edu.sg
//
//
//

#include <iostream>
#include <cmath>
using namespace std;

bool isZero(float num, float epsilon = 1e-6) {
    return fabs(num) < epsilon;  // Check if num is very close to 0
}

float calculate(float x, float y, char op){
    if(op == '+'){
        return x+y;
    }
    else if(op == '-'){
        return x-y;
    }
    else if(op == '*'){
        return x*y;
    }
    else if(op == '/'){
        if(isZero(y)){
            cout << "ERROR!";
            return 0;
        }
        return x/y;
    }
    return -1;
}



int main() {
    cout << "Addition (10 + 5): " << calculate(10, 5, '+') << endl;
    cout << "Subtraction (10.5 - 3.2): " << calculate(10.5, 3.2, '-') << endl;
    cout << "Multiplication (4 * 2): " << calculate(4, 2, '*') << endl;
    cout << "Division (10 / 2): " << calculate(10, 2, '/') << endl;
    cout << "Division (10.6 / 0.0): " << calculate(10.6, 0.0, '/') << endl;
    cout << "Division by zero (10 / 0): " << calculate(10, 0, '/') << endl;
    return 0;
}

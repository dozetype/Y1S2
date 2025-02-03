#include <stdio.h>
#include <math.h>

//Question 1
// int number;
// int *p;
// For each case below, determine the value of
//  (a) number (b) &number (c) p (d) &p (e) *p
// All of the results are cumulative.

// (i) p = 100;(ERROR, cannot change address) number = 8
//  (a) number=8 (b) &number=7700 (c) p=100 (d) &p=Address for pointer p (e) *p=uninitialized value

// (ii) number = p
//  cannot assign *int to int

// (iii) p = &number
// (a) number=8 (b) &number=7700 (c) p=7700 (d) &p=Address for pointer p (e) *p=8

// (iv) *p = 10
// (a) number=10 (b) &number=7700 (c) p=7700 (d) &p=Address for pointer p (e) *p=10

// (v) number = &p
// ERROR trying to assign int** to int

// (vi) p = &p
// ERROR trying to assign int** to int*

//Qn 2
int digitValue1(int num, int k);
void digitValue2(int num, int k, int *result);

//Qn 3
int extOddDigits1(int num);
void extOddDigits2(int num, int *result);

//Qn 4
void inputXY(double *x1, double *y1, double *x2, double *y2);
void outputResult(double dist);
double calDistance1(double x1, double y1, double x2, double y2);
void calDistance2(double x1, double y1, double x2, double y2, double *dist);

int pointer(int *num){
    (*num)++;
    return *num;
}

int main(void){
    int x = 10101, y = 328977;
    int num=1234567, digit=5, result=-1;
    x ^= y; y ^= x; x ^= y;
    printf("Magic Swap:\nx=%d, y=%d\n\n", x, y);

    printf("Question 2\n");
    printf("Part 1 result: %d\n", digitValue1(num, digit));
    digitValue2(num, digit, &result);
    printf("Part 2 result: %d\n", result);
    putchar('\n');

    printf("Question 3\n");
    printf("Part 1 result: %d\n", extOddDigits1(num));
    extOddDigits2(num, &result);
    printf("Part 2 result: %d\n", result);
    putchar('\n');

    printf("Question 4\n");
    double x1, y1, x2, y2, distance=-1; 
    inputXY(&x1, &y1, &x2, &y2);
    distance = calDistance1(x1, y1, x2, y2);
    printf("calDistance1(): ");
    outputResult(distance);
    calDistance2(x1, y1, x2, y2, &distance);
    printf("calDistance2(): ");
    outputResult(distance);
    putchar('\n');
    return 0;
}


//Question 2
int digitValue1(int num, int k){
    for(int i=1; i<k; i++){
        num /= 10;
    }
    return num%10;
}
void digitValue2(int num, int k, int *result){
    *result = digitValue1(num, k);
}

//Question 3
int extOddDigits1(int num){
    int power=1, total=0, digit;
    while(num>0){
        digit = num%10;
        num/=10;
        if(digit%2==1){
            total += digit*power;
            power*=10;
        }
    }
    return (power==1) ? -1:total;
}
void extOddDigits2(int num, int *result){
    *result = extOddDigits1(num);
}

//Question 4
void inputXY(double *x1, double *y1, double *x2, double *y2){
    printf("Enter x1:\n");
    scanf("%lf", x1);
    printf("Enter y1:\n");
    scanf("%lf", y1);
    printf("Enter x2:\n");
    scanf("%lf", x2);
    printf("Enter y2:\n");
    scanf("%lf", y2);
}
void outputResult(double dist){
    printf("The distance: %.2lf\n",dist);
}
double calDistance1(double x1, double y1, double x2, double y2){
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}
void calDistance2(double x1, double y1, double x2, double y2, double *dist){
    *dist = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}
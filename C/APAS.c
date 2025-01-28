#include <stdio.h>
int gcd1(int num1, int num2);
void computeNetPay();

int main()
{    
   return 0;
}
int gcd1(int num1, int num2)  
{
    int gcd=num1;
    if(num1>num2) gcd = num2;
    while(num1%gcd!=0 || num2%gcd!=0){
        gcd--;
    }
    return gcd;
}

void computeNetPay(){
    int hours;
    float pay, tax;
    printf("Enter hours of work: \n");
    scanf("%d", &hours);
    if(hours>40) pay = 40*6 + (hours-40)*9;
    else pay = hours*6;
    if(pay<=1000) tax=pay*0.1;
    else if(pay<=1500) tax=pay*0.2;
    else tax=pay*0.3;
    printf("Gross pay=%.2f", pay);
    printf("Tax=%.2f", tax);
    printf("Net pay=%.2f", pay-tax);
    


}

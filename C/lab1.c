#include <stdio.h>

void qn1();
void qn2();

int main(){
    qn1();
    qn2();
    return 0;
}

void qn2(){ //W tech
    int count=0, input=0, times=0;
    float sum=0;
    printf("Enter number of lines: \n");
    scanf("%d", &times);
    for(int i=1; i<=times; i++){
        printf("Enter line %d (end with -1):", i);
        scanf("%d", &input);
        while(input != -1){
            count++;
            sum += input;
            scanf("%d", &input);
        }
        printf("Average = %.2f \n", sum/count);
        sum = 0; count=0;
    }
}

void qn1(){
    int studentID = -1;
    int mark = 0;
    while (1){
        printf("Enter Student ID: \n");
        scanf("%d", &studentID);
        if(studentID==-1) break;
        printf("Enter Mark: \n");
        scanf("%d", &mark);
        printf("Grade = ");
        if(mark<=100 && mark>=75) putchar('A');
        else if(mark<=74 && mark>=65) putchar('B');
        else if(mark<=64 && mark>=55) putchar('C');
        else if(mark<=54 && mark>=45) putchar('D');
        else putchar('F');
        putchar('\n');
    }
}
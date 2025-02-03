// #include <stdio.h>
// int digitPos1(int num, int digit);
// void digitPos2(int num, int digit, int *result);
// int main()
// {
//  int number, digit, result=0;
//  printf("Enter the number: \n");
//  scanf("%d", &number);
//  printf("Enter the digit: \n");
//  scanf("%d", &digit);
//  printf("digitPos1(): %d\n", digitPos1(number, digit));
//  digitPos2(number, digit, &result);
//  printf("digitPos2(): %d\n", result);
//  return 0;
// }
// int digitPos1(int num, int digit)
// {
//  int pos=0;
//  do {
//  pos++;
//  if (num%10 == digit){ 
//     return pos;
//  break;
//  }
//  num = num/10;
//  } while (num > 0);
//  return 0;
// }
// void digitPos2(int num, int digit, int *result)
// {
//  int pos=0;
//  *result=0;
//  do {
//  pos++;
//  if (num%10 == digit){ 
//  *result = pos;
//  break;
//  }
//  num = num/10;
//  } while (num > 0);
// } 



#include <stdio.h>
int square1(int num);
void square2(int num, int *result);
int main()
{
 int number, result=0;
 printf("Enter the number: \n");
 scanf("%d", &number); 
 printf("square1(): %d\n", square1(number));
 square2(number, &result);
 printf("square2(): %d\n", result);
 return 0;
}
int square1(int num){
    int ans = 0;
    int curr = 1;
    for(int i=0; i<num; i++){
        ans += curr;
        curr += 2;
    }
    return ans;
}
void square2(int num, int *result){
    int curr = 1;
    for(int i=0; i<num; i++){
        *result += curr;
        curr += 2;
    }
} 
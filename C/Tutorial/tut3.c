// 1D: arr[], arr is just a pointer
// int *ptr = arr;
// arr == ptr (both points to first index)
// arr[i] == *(ptr+i)

// 2D: arr[][]
// ar+i == &ar[i](), *(ar+i) == ar[i](can == index || pointer) 
//**ar == the value of ar[0][0] (only works in main)
//First dimension can be omitted bc array is just a line at the end of the day, and it doesnt need to know the
//exact dimension, it just need to know how many cols in each row for offsetting.

#include <stdio.h>
#include <stdlib.h>

// #define SIZE 4
// void qn1();
// void qn2(int ar[][SIZE]);
// void qn3(int ar[][SIZE]);

// int main(void){
//     int ar[4][4] = {
//         {1, 2, 3, 4},
//         {5, 1, 2, 2},
//         {6, 3, 4, 4},
//         {7, 5, 6, 7}
//     };
//     // qn2(ar);
//     qn3(ar);
// }

// void qn1(){
//     int N, histStart=0;
//     int nums[10];
//     printf("Enter the histogram size: ");
//     scanf("%d", &N);
//     for(int i=0; i<N; i++){
//         nums[(rand()%100)/10] += 1;
//     }
//     printf("%d - %d    |", histStart, histStart+9);
//     for(int i=0; i<nums[0]; i++){
//         putchar('*');
//     }
//     putchar('\n');
    
//     for(int i=1; i<10; i++){
//         printf("%d - %d  |", histStart+(10*i), histStart+(10*i)+9);
//         for(int j=0; j<nums[i]; j++){
//             putchar('*');
//         }
//         putchar('\n');
//     }
// }

// void qn2(int ar[][SIZE]){
//     int arT[4][4];
//     for(int i=0; i<4; i++){
//         for(int j=0; j<4; j++){
//             arT[j][i] = ar[i][j];
//         }
//     }

//     for(int i=0; i<4; i++){
//         for(int j=0; j<4; j++){
//             printf("%d ", arT[i][j]);
//         }
//         putchar('\n');
//     }  
// }

// void qn3(int ar[][SIZE]){
//     int diagonal = 0;
//     int res[SIZE][SIZE];
//     for(int i=0; i<4; i++){
//         int colSum = 0;
//         for(int j=diagonal; j<4; j++){
//             res[i][j] = ar[i][j];
//             colSum += ar[j][i];
//             if(j>diagonal) res[j][i] = 0; 
//         }
//         res[diagonal][i] = colSum;
//         diagonal++;
//     }
//     for(int i=0; i<4; i++){
//         for(int j=0; j<4; j++){
//             printf("%d ", res[i][j]);
//         }
//         putchar('\n');
//     }  
// }


void add1(int ar[], int size);
int main(){
    int array[3][4];
    int h,k;
    for (h = 0; h < 3; h++)
        for (k = 0; k < 4; k++)
            scanf("%d", &array[h][k]);

    //
    add1(array[0], 12); //same thing would happen as each row is just linked tgt,
// and array[0] is just a pointer to the head
    //
    // for (h = 0; h < 3; h++) /* line a */
    //     add1(array[h], 4); //addition of 1 is done by add1 fn, passing each row of 4 into it
    for (h = 0; h < 3; h++) {
        for (k = 0; k < 4; k++)
            printf("%10d", array[h][k]);
        putchar('\n');
    }
    return 0;
}

void add1(int ar[], int size){
    int k;
    for (k = 0; k < size; k++)
        ar[k]++;
}


//////////////////////////////////////test//////////////////////////////////
// void max(int arr[][4]){
//     int *ptr = *arr;
//     printf("%p, %p\n", ptr, &arr[0][0]);
//     for(int i=0; i<3; i++){
//         for(int j=0; j<4; j++){
//             printf("%d\n", arr[i][j]);
//             printf("%d\n", *((ptr+i)+j));
//             printf("%d\n", *(ptr++));
//             putchar('\n');
//         }
//     }
// }

// int main( ){
//     int arr[3][4] = {{1,2,3}, {4,5,6}};
//     int *ptr = *arr;
//     // max(arr);
//     for(int i=0; i<12; i++){
//         // for(int j=0; j<4; j++){
//         //     printf("%d\n", arr[i][j]);
//         //     // printf("%p, %d\n", (arr+i), *arr==arr[0]);
//         //     printf("%d\n", *(ptr++));
//         //     putchar('\n');
//         // }
//     }
//     return 0;
// }
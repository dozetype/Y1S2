#include <stdio.h>

int binarySearch(int target, int list[], int len);
int bubbleSort(int list[], int len);
int mergeSort(int list[], int left, int right);
int merge(int list[], int left, int right, int mid);

int main(void){
    int list[] = {9,8,7,6,2342,5,4,3,2,1};
    int len = sizeof(list) / sizeof(list[0]);
    printf("Merge Sort: ");
    mergeSort(list, 0, len-1);
    for(int i=0; i<len; i++){
        printf("%d ", list[i]);
    }
    // printf("bubble sort\n");
    // bubbleSort(list, len); //dk why cannot find size of array in fn. Hence, passing it as an arg
    // binarySearch(74845, list, len); //seems like the list in main got sorted after passing it into bubbleSort
}

int mergeSort(int list[], int left, int right){
    if(left < right){
        int mid = (left+right)/2;
        mergeSort(list, left, mid); //left branch
        mergeSort(list, mid+1, right); //right branch
        merge(list, left, right, mid); //merge and sort the branches
    }
}

int merge(int list[], int left, int right, int mid){
    int i=0, j=0, k=left; //i and j for tracking left and right, k for starting pos
    int leftSize = mid - left + 1; 
    int rightSize = right - mid;
    int tempL[leftSize]; 
    int tempR[rightSize];
    for(int i=0; i<leftSize; i++){ //copy the values in index into temp
        tempL[i] = list[left+i];
    }
    for(int i=0; i<rightSize; i++){
        tempR[i] = list[mid+i+1];
    }

    while(i<leftSize && j<rightSize){ //have to used &&, bc if left is all smaller right will not be touched at all
        if(tempL[i] < tempR[j]){
            list[k] = tempL[i];
            i++;
        }
        else{
            list[k] = tempR[j];
            j++;
        }
        k++;
    }

    while(i<leftSize){
        list[k] = tempL[i];
        i++;
        k++;
    }

    while(j<rightSize){
        list[k] = tempR[j];
        j++;
        k++;
    }
}

int binarySearch(int target, int list[], int len){
    int low=0, high=len, mid;
    while(low<=high){
        mid = (low+high) / 2;
        // printf("%d\n", list[mid]);
        if(list[mid]==target){
            printf("found %d\n", target);
            return 0;
        }
        else if(list[mid]<target) low = mid+1;
        else high = mid-1;
    }
    printf("not found\n");
    return 1;
}

int bubbleSort(int list[], int len){
    for(int i=0; i<len; i++){
        for(int j=0; j<len-1; j++){
            if(list[j] > list[j+1]){
                int temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
    for(int i=0; i<len; i++){
        printf("%d ", list[i]);
    }
    putchar('\n');
}
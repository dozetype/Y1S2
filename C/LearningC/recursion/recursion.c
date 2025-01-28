#include <stdio.h>

int draw(int size){
    if(size<=0){
        return 0;
    }
    for(int i=0; i<size; i++){
        putchar('*');
    }
    putchar('\n');
    return draw(size-1);
}
int main(void){
    draw(8);
}
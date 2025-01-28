#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>

void draw();
void logic();
void input();

int width=25, height=15;
int playerX=0, playerY=0, playerLen=0, direction=0, gameOver=0;
int playerTailX[100], playerTailY[100];
int fruit[2] = {0,0};

int main(void){
    //Setting up
    srand(time(NULL)); //need to call this, else the seed for rand() will always be the same
    playerX=width/2, playerY=height/2; //spawn player in centre
    fruit[0] = rand() % (height-1) + 1;
    fruit[1] = rand() % (width-1) + 1;
    while(!gameOver){ //keep runnning until we lose
        input();
        logic();
        draw();
        Sleep(200);
    }
}

void draw(){
    system("cls"); //Clears console
    for(int i=0; i<=width; i++) putchar('#'); //first line of border
    putchar('\n');
    for(int y=1; y<=height-1; y++){
        putchar('#');
        for(int x=1; x<=width-1; x++){
            if(y==playerY && x==playerX) putchar('X'); //player
            else if(y==fruit[0] && x==fruit[1]) putchar('F'); //fruit

            else{ //check tail and empty space
                bool tail = false;
                for(int i=0; i<playerLen; i++){
                    if(x==playerTailX[i] && y==playerTailY[i]){
                        putchar('x');
                        tail = true;
                        break;
                    }
                }
                if(!tail) putchar(' ');
            }
        }
        putchar('#');
        putchar('\n');
    }
    for(int i=0; i<=width; i++) putchar('#'); //last line of border
    putchar('\n');
    printf("pressv x to exit");
}

void logic() {
    //Handling tail pos
    int prevX = playerTailX[0];
    int prevY = playerTailY[0];
    playerTailX[0] = playerX;
    playerTailY[0] = playerY;
    for(int i=1; i<playerLen; i++){
        int tempX = playerTailX[i];
        int tempY = playerTailY[i];
        playerTailX[i] = prevX;
        playerTailY[i] = prevY;
        prevX = tempX;
        prevY = tempY;
    }

    //handling player movement
    switch (direction){
        case 1:
            playerY--;
            break;
        case 2:
            playerX++;
            break;
        case 3:
            playerY++;
            break;
        case 4:
            playerX--;
            break;
        default:
            break;
    }

    if(playerX<=0 || playerX>=width || playerY<=0 || playerY>=height){ //check border
        gameOver = 1;
    }
    if(playerX==fruit[1] && playerY==fruit[0]){ //check touch fruit
        playerLen++;
        fruit[0] = rand() % (height-1) + 1;
        fruit[1] = rand() % (width-1) + 1;
    }
    for(int i=0; i<playerLen; i++){ //check touch tail
        if(playerX==playerTailX[i] && playerY==playerTailY[i]) gameOver = 1;
    }
}

void input(){
    if (kbhit()){
        switch (tolower(getch()))
        {
        case 'w':
            if(direction != 3) direction = 1; //moving up
            break;
        case 'd':
            if(direction != 4) direction = 2; //right
            break;
        case 's':
            if(direction != 1) direction = 3; //down
            break;
        case 'a':
            if(direction != 2) direction = 4; //left
            break;
        case 'x': //END
            gameOver = 1;
            break;
        }

    }
}
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>


void draw(char *spaces);
void playerTurn(char *spaces);
void computerTurn(char *spaces);
int checkWin(char *spaces);

int main(void){
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    bool gameOver = false;

    draw(spaces);
    getchar();
    while (!gameOver){
        draw(spaces);
        playerTurn(spaces);
        draw(spaces);
        computerTurn(spaces);
        draw(spaces);
        if(checkWin(spaces)==2 && checkWin(spaces)==1){
            printf("tie");
            gameOver=true;
        }
        else if(checkWin(spaces)==2){
            printf("lose");
            gameOver=true;
        }
        else if(checkWin(spaces)==1){
            printf("win");
            gameOver=true;
        }
    }
    system("pause");
    return 0;
}

void draw(char *spaces){
    system("cls"); //Clears console
    putchar('\n');
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", spaces[0], spaces[1], spaces[2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", spaces[3], spaces[4], spaces[5]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", spaces[6], spaces[7], spaces[8]);
    printf("     |     |     \n");
    putchar('\n');
}  

void playerTurn(char *spaces){
    int player;
    while(1){
        printf("Where u wanna place marker(1-9)?: ");
        scanf("%d", &player);
        if(spaces[player-1] == ' ') break;
    }
    spaces[player-1] = 'X';
}

void computerTurn(char *spaces){
    srand(time(NULL));
    int computer;
    while(1){
        computer = rand() % 9;
        if(spaces[computer] == ' ') break;
    }
    spaces[computer] = 'O';
}

int checkWin(char *spaces){
    int result = 0;
    if((spaces[0]!=' ') && (spaces[0]==spaces[1]) && (spaces[1]==spaces[2]))
        result = spaces[0]=='X'? 1 : 2;
    else if((spaces[3]!=' ') && (spaces[3]==spaces[4]) && (spaces[4]==spaces[5]))
        result = spaces[3]=='X'? 1 : 2;
    else if((spaces[6]!=' ') && (spaces[6]==spaces[7]) && (spaces[7]==spaces[8]))
        result = spaces[6]=='X'? 1 : 2;
    else if((spaces[0]!=' ') && (spaces[0]==spaces[3]) && (spaces[3]==spaces[6]))
        result = spaces[0]=='X'? 1 : 2;
    else if((spaces[1]!=' ') && (spaces[1]==spaces[4]) && (spaces[4]==spaces[7]))
        result = spaces[1]=='X'? 1 : 2;
    else if((spaces[2]!=' ') && (spaces[2]==spaces[5]) && (spaces[5]==spaces[8]))
        result = spaces[2]=='X'? 1 : 2;
    else if((spaces[0]!=' ') && (spaces[0]==spaces[4]) && (spaces[4]==spaces[8]))
        result = spaces[0]=='X'? 1 : 2;
    else if((spaces[2]!=' ') && (spaces[2]==spaces[4]) && (spaces[4]==spaces[6]))
        result = spaces[2]=='X'? 1 : 2;
    printf("%d", result);
    return result;
}
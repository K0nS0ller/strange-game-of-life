#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

//you can change it, if you need to change field size
#define ROW 100
#define COLUMN 100

struct block {
    bool alive;
    int alive_around;
};

struct block grid[ROW][COLUMN];

int rand_sub;

int randnum(){
    srand(time(NULL) + rand_sub);
    int randNum = rand() % 101;
    return randNum;
}

void begin(){
    for(int r = 1; r != ROW; r++){
        for(int c = 1; c != COLUMN; c++){
            grid[r][c].alive_around = 0;
            grid[r][c].alive = false;
        }
    }

    for(int r = 1; r < ROW; r++){
        for(int c = 1; c < COLUMN; c++){
            if(randnum() % 101 < 1){ //chance of block aliving in beginning
                grid[r][c].alive = true;
            }
            rand_sub++;
        }
    }
}



int life;

void field_print(){
    system("clear");
    life = 0;
    for(int c = 1; c < COLUMN; c++){
        for(int r = 1; r < ROW; r++){
            if(r - 1 <= 0 || r + 1 >= ROW){
                printf("|");
            } else{
                if(c - 1 <= 0 || c + 1 >= COLUMN){
                    printf("-");
                }else{
                    if(grid[r][c].alive){
                        printf("\033[44m \033[0m");
                        life++;
                    } else{
                        printf(" ");
                    }
                }
            }
        }
        printf("\n");
    }
}



void check(int raround, int caround, int r, int c){
    if(raround < ROW && raround > 0 && caround < COLUMN && caround > 0){
        if(grid[raround][caround].alive){
            grid[r][c].alive_around++;
        }
    }
}

void logic(){
    for(int row = 1; row < ROW; row++){
        for(int column = 1; column < COLUMN; column++){
            grid[row][column].alive_around = 0;
                int r_around = row - 1;
                int c_around = column - 1;
                for(r_around; r_around != row + 1; r_around++){
                    check(r_around, c_around, row, column);
                }
                for(c_around; c_around != column + 1; c_around++){
                    check(r_around, c_around, row, column);
                }
                for(r_around; r_around != row - 1; r_around--){
                    check(r_around, c_around, row, column);
                }
                for(c_around; c_around != column - 1; c_around--){
                    check(r_around, c_around, row, column);
                }

//RULES!!!
                if(grid[row][column].alive_around == 2){
                    grid[row][column].alive = true;
                } else{
                    grid[row][column].alive = false;
                }

        }
    }
}

float frametime = 1.0;

int main(){
    begin();
    field_print();
    sleep(frametime);
    do{
        logic();
        field_print();
        printf("\nживо: %d\n", life);
        sleep(frametime);
    }while(life > 0);
    printf("все клетки мертвы\n");
    return 0;
}

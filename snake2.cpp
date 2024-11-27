#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>

using namespace std;

#define VL cout<<"|";
#define HL cout<<"_";
#define NL cout<<endl;

#define side 20
#define loop1 30
#define loop2 100
#define ST 300000


char box[side][side];

void boxNull();
void printbox();
void xbox(int, int);
void dirn(int, int);
int abs(int, int);
void updatesnake(int, int);
void drawsnake();
void stail(int, int);
void startsnake(int, int);


#define maxSlen 100
int snakeX[maxSlen], snakeY[maxSlen];
int snakelen = 3;



int main(){

srand(time(0));

int r, c;
int x=3, y=3;
int x1=2, y1=2, x2=1, y2=1;



boxNull();
// printbox();
startsnake(x, y);





for(int i=0; i<loop1; i++){

    r = rand()%side;
    c = rand()%side;


  for( ; ; ){
    
    xbox(r, c);
    updatesnake(x, y);
    drawsnake();

    printbox();
    boxNull();
    

    if(r == x){
        break;
    }
    if(r<x){
        x--;
        x1--;
        x2--;
    }    
    if(r>x){
        x++;
        x1++;
        x2++;
    }



    usleep(ST);
  
  }


  for( ; ; ){
    
    xbox(r, c);
    updatesnake(x,y);
    drawsnake();

    printbox();
    boxNull();


    if(c == y){
        break;
    }
    if(c<y){
        y--;
        y1--;
        y2--;
    }    
    if(c>y){
        y++;
        y1++;
        y2++;
    }

  


    usleep(ST);

  }

}




    return 0;
}





void boxNull(){
    for(int i=0; i<side; i++){
        for(int j =0; j<side; j++){
            box[i][j] = ' ';
        }
    }
}



void updatesnake(int newHeadX, int newHeadY) {

    for (int i = snakelen - 1; i > 0; i--) {
        snakeX[i] = snakeX[i - 1];
        snakeY[i] = snakeY[i - 1];
    }

    snakeX[0] = newHeadX;
    snakeY[0] = newHeadY;
}



void drawsnake() {
    for (int i = 0; i < snakelen; i++) {
        if (i == 0)
            box[snakeX[i]][snakeY[i]] = 'o'; // Head
        else
            box[snakeX[i]][snakeY[i]] = 'c'; // Body
    }
}



void stail(int x1, int y1){
    box[x1][y1] = 'c';
}



void xbox(int r, int c){
    box[r][c] = 'x';
}




void printbox(){

    for(int i=0; i<3*side+2; i++){
        cout<<"-";
    }
        NL;

    for(int i=0; i< side; i++){
            VL;
        for(int j =0; j<side; j++){
            cout<<" "<<box[i][j]<<" ";
        }
            VL;
            NL;
    }

    for(int i=0; i<3*side+2; i++){
        cout<<"-";
    }
        NL;
}




int abs(int a, int b){
    int c = a-b;
    if(c > 0)
    return c;

    return (c*(-1));
}




void startsnake(int X, int Y) {
    for (int i = 0; i < snakelen; i++) {
        snakeX[i] = X - i; 
        snakeY[i] = Y;
    }
}


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>

using namespace std;

#define VL cout<<"|";
#define HL cout<<"_";
#define NL cout<<endl;

#define side 30
#define loop1 30
#define loop2 100
#define ST 200000



char box[side][side];

void boxNull();
void printbox();
void xbox(int, int);
void dirn(int, int);
int abs(int, int);
void snake(int, int);









int main(){

srand(time(0));

int r, c;
int x=0, y=0;


boxNull();
printbox();










for(int i=0; i<loop1; i++){


    r = rand()%side;
    c = rand()%side;


if( abs(r,x) > abs(c,y)){ 

  for(int j=0; ; j++){
    
    xbox(r, c);
    snake(x, y);

    printbox();
    boxNull();
    

    if(r == x){
        break;
    }
    if(r<x){
        x--;
    }    
    if(r>x){
        x++;
    }


    usleep(ST);
  
  }
}

else{
  for(int j=0;  ; j++){
    
    xbox(r, c);
    snake(x, y);

    printbox();
    boxNull();


    if(c == y){
        break;
    }
    if(c<y){
        y--;
    }    
    if(c>y){
        y++;
    }
    
    usleep(ST);

  }
}


if( abs(r,x) < abs(c,y)){ 

  for(int j=0;  ; j++){
    
    xbox(r, c);
    snake(x, y);

    printbox();
    boxNull();


    if(c == y){
        break;
    }
    if(c<y){
        y--;
    }    
    if(c>y){
        y++;
    }
    
    usleep(ST);

  }
}

else{
  for(int j=0; ; j++){
    
    xbox(r, c);
    snake(x, y);

    printbox();
    boxNull();
    

    if(r == x){
        break;
    }
    if(r<x){
        x--;
    }    
    if(r>x){
        x++;
    }


    usleep(ST);
  
  }

}



}   // main loop1 ends;








    return 0;
}




void snake(int x, int y){

    box[x][y] = 'o';

}



void boxNull(){
    for(int i=0; i<side; i++){
        for(int j =0; j<side; j++){
            box[i][j] = ' ';
        }
    }
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






#include<bits/stdc++.h>
#include<conio.h>
#include <windows.h>
using namespace std;

bool gameOver;
const int frameWidth = 50;
const int frameHeight = 20;
int headX, headY, fruitX, fruitY, score;
int tailX[100], tailY[100];
int tail_length;
enum direction {stop=0, Left, Right, Up, Down};
direction dir;
void setup()
{
    gameOver=false;
    dir=stop;
    headX=frameWidth/2;
    headY=frameHeight/2;
    srand(time(0));
    fruitX=rand()%(frameWidth-2)+1;
    fruitY=rand()%(frameHeight-2)+1;
    score=0;
    tail_length = 0;
}
void draw()
{
    system("cls");
    for( int i=0; i<frameWidth; i++){
        cout<<"#";
    }
    cout<<endl;
    for (int i = 0; i < frameHeight - 2; i++) {
        for (int j = 0; j < frameWidth; j++) {
            if (j == 0 || j == frameWidth - 1) {
                cout << "#";
            }
            else if(i==headY && j==headX){
                cout<<"0";
            }
            else if(i==fruitY && j==fruitX){
                cout<<"@";
            }
            else {
                bool isTail= false;
                for(int k=0; k<tail_length; k++){
                    if(tailX[k]==j && tailY[k]==i){
                        cout<<"o";
                        isTail= true;
                        break;
                    }
                }
                if(! isTail){
                    cout<<" ";
                }
            }
        }
        cout<<endl;
    }
    for( int i=0; i<frameWidth; i++){
        cout<<"#";
    }
    cout << endl;
    cout << "Score: " << score << endl;
}
void input()
{
    if(_kbhit()){
        switch (_getch())
        {
        case 'a':
            dir=Left;
            break;
        case 'd':
            dir=Right;
            break;
        case 'w':
            dir=Up;
            break;
        case 's':
            dir=Down;
            break;
        case 'x':
            gameOver=true;
            break;
        }
     }
}
void logic()
{
    //tail movement
    int prevX, prevY, prev2X, prev2Y;
    prevX=headX;
    prevY=headY;
    tailX[0]=prevX;
    tailY[0]=prevY;

    for(int i=1; i<tail_length; i++){
        prev2X=tailX[i];
        prev2Y=tailY[i];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prev2X;
        prevY=prev2Y;
    }
    //head movement
    switch(dir){
    case Left:
        headX--;
        break;
    case Right:
        headX++;
        break;
    case Up:
        headY--;
        break;
    case Down:
        headY++;
        break;
    default:
        break;
    }
    // Check for collision with walls
    if(headX>=frameWidth-1 || headX <= 0 || headY>= frameHeight-1 || headY <= 0){
        gameOver = true;
    }
    // Check if the snake eats the fruit
    if (headX == fruitX && headY == fruitY) {
        score++;
        fruitX = rand() % (frameWidth - 2) + 1;
        fruitY = rand() % (frameHeight - 2) + 1;
        tail_length++;
        
    }
}
int main(){
    setup();
    while(! gameOver)
    {
        draw();
        input();
        logic();
        Sleep(100);
    }
return 0;
}

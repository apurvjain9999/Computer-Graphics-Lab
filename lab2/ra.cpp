#include<graphics.h>
#include<iostream>
#include<cmath>
using namespace std;

int DDA(int X0, int Y0, int X1, int Y1)
{
    int steps;
    int dx = X1 - X0;
    int dy = Y1 - Y0;

    /*if(dx > dy)
    {
        steps = dx;
    }
    else
    {
        steps = dy;
    }*/

    steps = abs(dx)>abs(dy)?abs(dx):abs(dy);

    float incX = dx/(float)steps;
    float incY = dy/(float)steps;

    float X = X0;
    float Y = Y0;
    for(int i = 0; i<=steps;i++)
    {
        putpixel(X,Y,WHITE);
        X = X + incX;
        Y = Y + incY;
        delay(5);
    }
}

int main()
{
    //int X1,X0,Y1,Y0;
    int gd = DETECT, gm;
   /* cout<<"Enter the X and Y Co-ordinates of first point: ";
    cin>>X0>>Y0;
    cout<<"Enter the X and Y Co-ordinates of second point: ";
    cin>>X1>>Y1;*/

    initgraph(&gd, &gm, "");
    DDA(200,400,600,400);
    DDA(600,400,600,200);
    DDA(600,200,200,200);
    DDA(200,200,400,100);
    DDA(400,100,600,200);
    DDA(200,200,200,400);
    DDA(250,350,300,350);
    DDA(300,350,300,300);
    DDA(300,300,250,300);
    DDA(250,300,250,350);
    DDA(250,325,300,325);
    DDA(275,350,275,300);
   // DDA(X1,Y1,X0, 520);
    return 0;
}

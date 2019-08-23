#include<graphics.h>
#include<iostream>
#include<stdio.h>
using namespace std;

void draw_line(int X1, int Y1, int X2, int Y2)
{
    int dx, dy;
    dx = X2 - X1;
    dy = Y2 - Y1;

    int steps;

    int dx1 = dx;
    int dy1 = dy;
    if (dx1 < 0)
        dx1 = -dx;
    if (dy1 < 0)
        dy1 = -dy;

    if (dx1 > dy1)
        steps = dx1;
    else
        steps = dy1;
    float xInc = 0;
    float yInc = 0;
    xInc = dx / (float) steps;
    yInc = dy / (float) steps;

    int X0, Y0;
    X0 = X1;
    Y0 = Y1;

    int i = 0;
    for(i=0; i<=steps; i++)
    {
        putpixel(X0, Y0, WHITE);
        X0 += xInc;
        Y0 += yInc;
        delay(100);
    }
}

int main()
{
    cout<<"---- DDA Line Drawing Algorithm -----"<<endl;
    int X1, X2, Y1, Y2;
    int gd = DETECT, gm;
    cout<<"\nEnter Co-ordinates for point 1: \n";
    cin>>X1>>Y1;
    cout<<"\nEnter Co-ordinates for point 2: \n";
    cin>>X2>>Y2;
    initgraph(&gd, &gm, "");
    draw_line(X1, Y1, X2, Y2);
    getch();
    closegraph();
    return 0;
}

#include<graphics.h>
#include<iostream>
#include<stdio.h>
using namespace std;

void draw_line(int X1, int Y1, int X2, int Y2)
{
    int dx, dy;
    dx = X2 - X1;
    dy = Y2 - Y1;
    int pk;
    pk = 2 * dy - dx;
    int X0 = X1, Y0 = Y1;
    putpixel(X0, Y0, WHITE);
    while (X0 != X2 && Y0 != Y2)
    {
        if (pk < 0)
        {
            pk += 2 * dy;
            X0++;
        }
        else
        {
            pk += (2 * dy) - (2 * dx);
            X0++;
            Y0++;
        }
        putpixel(X0, Y0, WHITE);
        delay(100);
    }
}

int main()
{
    cout<<"---- Bresenham Line Drawing Algorithm -----"<<endl;
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


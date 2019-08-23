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
        //delay(10);
    }
    delay(1000);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    //draw_line(100, 500, 500, 500);
    //draw_line(500, 500, 500, 300);
    //draw_line(500, 300, 300, 300);
    //draw_line(100, 300, 300, 200);
    draw_line(300, 200, 500, 300);
    //draw_line(100, 300, 100, 500);
    /*draw_line(250, 350, 300, 350);
    draw_line(300, 350, 300, 300);
    draw_line(300, 300, 250, 300);
    draw_line(250, 300, 250, 350);
    draw_line(250, 325, 300, 325);
    draw_line(275, 350, 275, 300);*/
    getch();
    closegraph();
    return 0;
}


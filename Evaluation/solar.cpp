#include<graphics.h>
#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
#define ROUND(a) (int(a + 0.5))

int e1, e2;

int flag = 0;
int m1, m2;
//Draw elliptical path
void draw_points_e(int x, int y, int x1, int y1)
{
    //delay(100);
    putpixel(x1+x, y1+y, WHITE);
    putpixel(x1-x, y1+y, WHITE);
    putpixel(x1+x, y1-y, WHITE);
    putpixel(x1-x, y1-y, WHITE);
}

//Draw points of circle
void draw_points(int x, int y, int x1, int y1)
{
    //delay(5);
    putpixel(x1+x, y1+y, WHITE);
    putpixel(x1-x, y1+y, WHITE);
    putpixel(x1+x, y1-y, WHITE);
    putpixel(x1-x, y1-y, WHITE);
    putpixel(x1+y, y1+x, WHITE);
    putpixel(x1-y, y1+x, WHITE);
    putpixel(x1+y, y1-x, WHITE);
    putpixel(x1-y, y1-x, WHITE);
}

//For drawing ellipse
void ellipse(int a, int b, int x1, int y1)
{
    int x=0, y=b;
	putpixel(x+x1, y+y1, WHITE);
    int p = ROUND((b * b) - (a * a * b) + (0.25 * a * a));
    int inc1 = 2 * (b * b) * x;
    int inc2 = 2 * (a * a) * y;
    while(inc1 <= inc2)
    {
        x++;
        inc1 = 2 * (b * b) * x;
        if (p < 0)
        {
            p = ROUND(p + inc1 + (b*b));
            draw_points_e(x, y, x1, y1);
            e1 = x, e2 = y;
        }
        else
        {
            y--;
            inc2 = 2 * (a * a) * y;
            p = ROUND(p + inc1 - inc2 + (b*b));
            draw_points_e(x, y, x1, y1);
        }
    }
    p = ROUND(((b*b)*(x+0.5)*(x+0.5)) + ((a*a)*(y-1)*(y-1)) - (a*a*b*b));
    while(y > 0)
    {
        y--;
        inc2 = 2 * (a*a) * y;
        if (p < 0)
        {
            p = ROUND(p+(-inc2) + (a*a));
            draw_points_e(x, y, x1, y1);
        }
        else
        {
            x++;
            inc1 = 2 * (b * b) * x;
            p = ROUND(p + inc1 - inc2 + (b*b));
            draw_points_e(x, y, x1, y1);
        }

    }
}

//For drawing circle
void cir(int r, int x, int y, int x1, int y1)
{
    int p = 1 - r;
    while(x <= y)
    {
        x++;
        if (p < 0)
        {
            p += 2*x + 1;
            draw_points(x, y, x1, y1);
            m1 = x, m2 = y;
        }
        else
        {
            y--;
            p += 2*x + 1 - 2*y;
            draw_points(x, y, x1, y1);
        }
    }
}

//Draw points of the Sun
void sun(int x, int y, int x1, int y1)
{
     putpixel(x1+x, y1+y, YELLOW);
     putpixel(x1-x, y1+y, YELLOW);
     putpixel(x1+x, y1-y, YELLOW);
     putpixel(x1-x, y1-y, YELLOW);
     putpixel(x1+y, y1+x, YELLOW);
     putpixel(x1-y, y1+x, YELLOW);
     putpixel(x1+y, y1-x, YELLOW);
     putpixel(x1-y, y1-x, YELLOW);
}

//Draw points of the Earth
void ear(int x, int y, int x1, int y1)
{
     putpixel(x1+x, y1+y, BLUE);
     putpixel(x1-x, y1+y, BLUE);
     putpixel(x1+x, y1-y, BLUE);
     putpixel(x1-x, y1-y, BLUE);
     putpixel(x1+y, y1+x, BLUE);
     putpixel(x1-y, y1+x, BLUE);
     putpixel(x1+y, y1-x, BLUE);
     putpixel(x1-y, y1-x, BLUE);
}

void mo(int x, int y, int x1, int y1)
{
     putpixel(x1+x, y1+y, WHITE);
     putpixel(x1-x, y1+y, WHITE);
     putpixel(x1+x, y1-y, WHITE);
     putpixel(x1-x, y1-y, WHITE);
     putpixel(x1+y, y1+x, WHITE);
     putpixel(x1-y, y1+x, WHITE);
     putpixel(x1+y, y1-x, WHITE);
     putpixel(x1-y, y1-x, WHITE);
}

//Draw Sphere
void sphere(int r, int x1, int y1, int c)
{
    int x,y;
    float phi;
    float theta;
    float i,j;
    int p;
    for(phi = -1.57; phi<=0; phi += 0.05)
    {
        for(theta = -3.14; theta<=3.14; theta += 0.05)
        {
            x = r * cos(phi) * cos(theta);
            y = r * cos(phi) * sin(theta);
            putpixel(0, y, YELLOW);
            p = 1 - r;
            while(x <= y)
            {
                x++;
                if (p < 0)
                {
                    p += 2*x + 1;
                    if (c == 0)
                        sun(x,y,x1,y1);
                    if (c==1)
                        ear(x,y,x1,y1);
                    if (c==2)
                        mo(x,y,x1,y1);
                }
                else
                {
                    y--;
                    p += 2*x + 1 - 2*y;
                    if (c == 0)
                        sun(x,y,x1,y1);
                    if (c==1)
                        ear(x,y,x1,y1);
                    if (c==2)
                        mo(x,y,x1,y1);
                }
            }
        }
    }
}

void moon(int c1, int c2)
{
    int x1 = m1 + c1, y1 = m2 + c2;
    int r = 10;
    cir(r, 0, r, x1, y1);
    sphere(r, x1, y1, 2);
}
//Draw Earth
void earth(int p1, int p2, int a, int b)
{
    int r = 20;
    int x1 = e1 + p1, y1 = e2 + p2;
    int g = 0;
    /*while(x1 != p1 - e1 && y1 != p2 - e2)
    {
        if (g%5 == 0)
        {
            if ((((x1-p1)*(x1-p1))/(a*a) + ((y1-p2)*(y1-p2))/(b*b)) == 1)
            {
                cir(r, 0, r, x1, y1);
                sphere(r, x1, y1, 1);
                x1++;
                y1++;
            }
        }
        else
        {
            continue;
        }
    }
    g++;*/
    cir(r, 0, r, x1, y1);
    sphere(r, x1, y1, 1);
    cir(40, 0, 40, x1, y1);
    moon(x1, y1);
}



int main()
{
    int r = 60;
    int x1 = 800, y1 = 400;
    int x=0, y=r;
    //int gd = DETECT, gm;
    //initgraph(&gd, &gm, "");
    initwindow(2000, 1000, "Solar System");
    putpixel(x+x1, y+y1, WHITE);
    cir(r, x, y, x1, y1);
    sphere(r, x1, y1, 0);
    ellipse(400, 200, 800, 400);
    earth(800, 400, 400, 200);
    getch();
    closegraph();
    return 0;
}

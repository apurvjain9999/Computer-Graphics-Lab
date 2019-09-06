#include<graphics.h>
#include<iostream>
#include<stdio.h>
using namespace std;

void draw_points(int x, int y, int x1, int y1)
{
    delay(100);
    putpixel(x1+x, y1+y, WHITE);
    putpixel(x1-x, y1+y, WHITE);
    putpixel(x1+x, y1-y, WHITE);
    putpixel(x1-x, y1-y, WHITE);
    putpixel(x1+y, y1+x, WHITE);
    putpixel(x1-y, y1+x, WHITE);
    putpixel(x1+y, y1-x, WHITE);
    putpixel(x1-y, y1-x, WHITE);
}

int main()
{
    cout<<"\n------ Midpoint Circle Algorithm ------\n";
    int r;
    cout<<"Enter Radius of the Circle : ";
    cin>>r;
    int x1, y1;
    cout<<"\nEnter the co-ordinates of the centre of the circle: ";
    cin>>x1>>y1;
    int x=0, y=r;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    putpixel(x+x1, y+y1, WHITE);
    int p = 1 - r;
    while(x <= y)
    {
        x++;
        if (p < 0)
        {
            p += 2*x + 1;
            draw_points(x, y, x1, y1);
        }
        else
        {
            y--;
            p += 2*x + 1 - 2*y;
            draw_points(x, y, x1, y1);
        }
    }
    getch();
    closegraph();
    return 0;
}

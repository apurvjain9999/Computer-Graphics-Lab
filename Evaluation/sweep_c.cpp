#include<graphics.h>
#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

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
    //int gd = DETECT, gm;
    //initgraph(&gd, &gm, "");
    initwindow(2000, 900, "sweep");
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
    float phi;
    float theta;
    float i,j;
    for(phi = -1.57; phi<=0; phi += 0.1)
    {
        for(theta = -3.14; theta<=3.14; theta += 0.2)
        {
            x = r * cos(phi) * cos(theta);
            y = r * cos(phi) * sin(theta);
            draw_points(0, y, x1, y1);
            p = 1 - r;
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
        }
    }
    getch();
    closegraph();
    return 0;
}

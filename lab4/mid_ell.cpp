#include<graphics.h>
#include<iostream>
#include<stdio.h>
using namespace std;
#define ROUND(a) (int(a + 0.5))
void draw_points(int x, int y, int x1, int y1)
{
    //delay(100);
    putpixel(x1+x, y1+y, WHITE);
    putpixel(x1-x, y1+y, WHITE);
    putpixel(x1+x, y1-y, WHITE);
    putpixel(x1-x, y1-y, WHITE);
}

int main()
{
    cout<<"\n------ Midpoint Ellipse Algorithm ------\n";
    int a, b;
    cout<<"Enter value of a : ";
    cin>>a;
    cout<<"Enter value of b : ";
    cin>>b;
    int x1, y1;
    cout<<"\nEnter the co-ordinates of the centre of the ellipse: ";
    cin>>x1>>y1;
    int x=0, y=b;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
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
            cout<<p<<"\t"<<x<<"\t"<<y<<"\t"<<inc1<<"\t"<<inc2<<endl;
            p = ROUND(p + inc1 + (b*b));
            draw_points(x, y, x1, y1);
        }
        else
        {
            y--;
            inc2 = 2 * (a * a) * y;
            cout<<p<<"\t"<<x<<"\t"<<y<<"\t"<<inc1<<"\t"<<inc2<<endl;
            p = ROUND(p + inc1 - inc2 + (b*b));
            draw_points(x, y, x1, y1);
        }

    }
    p = ROUND(((b*b)*(x+0.5)*(x+0.5)) + ((a*a)*(y-1)*(y-1)) - (a*a*b*b));
    while(y > 0)
    {
        y--;
        inc2 = 2 * (a*a) * y;
        if (p < 0)
        {
            cout<<p<<"\t"<<x<<"\t"<<y<<"\t"<<inc1<<"\t"<<inc2<<endl;
            p = ROUND(p+(-inc2) + (a*a));
            draw_points(x, y, x1, y1);
        }
        else
        {
            x++;
            inc1 = 2 * (b * b) * x;
            cout<<p<<"\t"<<x<<"\t"<<y<<"\t"<<inc1<<"\t"<<inc2<<endl;
            p = ROUND(p + inc1 - inc2 + (b*b));
            draw_points(x, y, x1, y1);
        }

    }
    getch();
    closegraph();
    return 0;
}


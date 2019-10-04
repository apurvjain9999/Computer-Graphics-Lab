#include<graphics.h>
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

void midPointCircleDraw(int xc,int yc,int a)
{
    int x = 0,y = 0;
    // int p = (5/4) - r;
    int p = 1 - 2*a ;
    while(2*a > y)
    {
        putpixel(x + xc,y + yc,WHITE); 
        // putpixel(-x + xc,y + yc,8); 
        putpixel(x + xc,-y + yc,WHITE); 
        // putpixel(-x + xc,-y + yc,8); 
        
        // if (x != y) 
        // { 
        //  putpixel(y + xc,x + yc,8); 
        //  putpixel(-y + xc,x + yc,8); 
        //  putpixel(y + xc,-x + yc,8); 
        //  putpixel(-y + xc,-x + yc,8); 
        // } 
        y++;
        if(p<0)
        {
            p += 2*y + 3 ;
            
        }
        else
        {
            ++x;
            p += 2*y + 3 - 4*a ;
            // --x;
        }
        // if(x>y)
        //  break;
        delay(500);
    }
    int count = 100;
    p = (y+0.5)*(y+0.5) - 4*a*(x+1);
    while(--count)
    {
        putpixel(x + xc, yc - y, WHITE);
        putpixel(x++ + xc, yc + y, WHITE);
        if(p < 0)
        {
            ++y;
            p += 2*(y+1) - 4*a;
        }
        else
            p += -4*a;
        delay(50);
    }
}

void flood(int x,int y)
{
    if(getpixel(x,y) == BLACK )
    {
        putpixel(x,y,RED);
        flood(x+1,y);
        flood(x-1,y);
        flood(x,y+1);
        flood(x,y-1);
    }
    delay(50);
}

int main()
{
    cout<<"\n------ Midpoint Circle Algorithm ------\n";
    int r;
    cout<<"Enter Radius of the Circle : ";
    cin>>r;
    int x, y;
    cout<<"\nEnter the co-ordinates of the centre of the circle: ";
    cin>>x>>y;
    //width of circle is w
    int w= 10;
    int x=0, y=r;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    midPointCircleDraw(x, y, r);
    midPointCircleDraw(x,y,r+w);
    flood_fill(x+r+w/2,y);
    return 0; 
    getch();
    closegraph();
    return 0;
}

#include <bits/stdc++.h>
#include<graphics.h>
using namespace std;
void ellipse(int rx, int ry,
				int xc, int yc)
{
	float dx, dy, p, p2, x, y;
	x = 0;
	y = ry;
	p = (ry*ry)-(rx*rx*ry)+(0.25*rx* x);
	dx = 2 * ry * ry * x;
	dy = 2 * rx * rx * y;
	while (dx < dy)
	{
	    putpixel(x+xc,y+yc, WHITE);
        delay(10);
        putpixel(-x+xc,y+yc,WHITE);
        delay(10);
        putpixel(x+xc,-y+yc,WHITE);
        delay(10);
        putpixel(-x+xc,-y+yc,WHITE);
        delay(10);
		if (p < 0)
		{
			x++;
			dx = dx + (2 * ry * ry);
			p = p + dx + (ry * ry);
		}
		else
		{
			x++;
			y--;
			dx = dx + (2 * ry * ry);
			dy = dy - (2 * rx * rx);
			p = p + dx - dy + (ry * ry);
		}
	}
	p2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) +
		((rx * rx) * ((y - 1) * (y - 1))) -
		(rx * rx * ry * ry);
	while (y >= 0)
	{
	    putpixel(x+xc,y+yc,WHITE);
        delay(10);
        putpixel(-x+xc,y+yc,WHITE);
        delay(10);
        putpixel(x+xc,-y+yc,WHITE);
        delay(10);
        putpixel(-x+xc,-y+yc,WHITE);
        delay(10);
		if (p2 > 0)
		{
			y--;
			dy = dy - (2 * rx * rx);
			p2 = p2 + (rx * rx) - dy;
		}
		else
		{
			y--;
			x++;
			dx = dx + (2 * ry * ry);
			dy = dy - (2 * rx * rx);
			p2 = p2 + dx - dy + (rx * rx);
		}
	}
}
int main()
{
    int gd = DETECT, gm;

    int a,b,x,y,i;
    cout<<"Enter length of major axis:";
    cin>>a;
    cout<<"Enter length of minor axis:";
    cin>>b;
    cout<<"Enter coordinates of centre of ellipse:";
    cin>>x>>y;
    initgraph (&gd, &gm, "");
    for(i=0;i<10;i++)
    {
        ellipse(a,b,x,y);
        a++;
        b++;
    }
    getch();
    closegraph();
	return 0;
}

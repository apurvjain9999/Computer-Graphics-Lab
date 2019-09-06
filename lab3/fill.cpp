#include<graphics.h>
#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    cout<<"\n----- Boundary Fill Algorithm -----\n";
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    //F
    line(60, 70, 150, 70);
    line(60, 70, 60, 300);
    line(80, 100, 150, 100);
    line(150, 70, 150, 100);
    line(60, 300, 80, 300);
    line(80, 160, 120, 160);
    line(80, 190, 120, 190);
    line(80, 100, 80, 160);
    line(120, 160, 120, 190);
    line(80, 190, 80, 300);
    line(80, 250, 80, 300);

    //R
    line(170, 70, 170, 300);
    line(190, 190, 220, 190);
    line(170, 300, 190, 300);
    line(190, 300, 190, 190);
    line(220, 190, 250, 300);
    line(250, 300, 270, 280);
    line(270, 280, 240, 185);
    arc(170, 150, 334, 90, 80);
    line(190, 100, 190, 170);
    arc(190, 135, 270, 90, 35);

    //D
    line(320, 70, 320, 300);
    line(350, 120, 350, 250);
    arc(320, 185, 270, 90, 115);
    arc(350, 185, 270, 90, 65);
    getch();
    closegraph();
    return 0;
}

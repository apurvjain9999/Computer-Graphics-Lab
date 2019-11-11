#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

string computeCode(int x_max, int x_min, int y_max, int y_min, int x, int y)
{
    string code = "";
    if (x < x_max)
        code += "0";
    else
        code += "1";

    if (y > y_min)
        code += "0";
    else
        code += "1";

    if (y < y_max)
        code += "0";
    else
        code += "1";

    if (x < x_min)
        code += "1";
    else
        code += "0";

    return code;
}

int si(string res)
{
    if (res == "0000")
        return 0;
    if (res == "0001")
        return 1;
    if (res == "0010")
        return 2;
    if (res == "0011")
        return 3;
    if (res == "0100")
        return 4;
    if (res == "0101")
        return 5;
    if (res == "1000")
        return 8;
    if (res == "1100")
        return 12;
    if (res == "1010")
        return 10;
}
int main()
{
    float x_max, x_min, y_max, y_min;
    float x, y, a, b;
    cout<<"------ Line Clipping Algorithm ------"<<endl;
    cout<<"Enter the co-ordinates of the viewing window"<<endl;
    cout<<"Enter x min: ";
    cin>>x_min;
    cout<<"Enter x max: ";
    cin>>x_max;
    cout<<"Enter y min: ";
    cin>>y_min;
    cout<<"Enter y max: ";
    cin>>y_max;

    cout<<"Enter the co-ordinates of the line"<<endl;

    cout<<"Enter the co-ordinates of the first point"<<endl;
    cout<<"Enter x co-ordinate: ";
    cin>>x;
    cout<<"Enter y co-ordinate: ";
    cin>>y;
    cout<<"Enter the co-ordinates of the second point"<<endl;

    cout<<"Enter x co-ordinate: ";
    cin>>a;
    cout<<"Enter y co-ordinate: ";
    cin>>b;

    string c1 = computeCode(x_max, x_min, y_max, y_min, x, y);
    string c2 = computeCode(x_max, x_min, y_max, y_min, a, b);
    int flag= 0;

    while(true)
    {
        if (c1 == "0000" && c2 == "0000")
        {
            flag = 1;
            break;
        }
        else if (si(c1) & si(c2))
            break;
        else
        {
            string co;
            float d, e;
            if (c1 != "0000")
                co = c1;
            else
                co = c2;

            if (si(co) & 8)
            {
                d = x + (a-x) * (y_max - y)/(b - y);
                e = y_max;
            }

            if (si(co) & 4)
            {
                d = x + (a-x) * (y_min - y)/(b - y);
                e = y_min;
            }

            if (si(co) & 2)
            {
                e = y + (b - y) * (x_max - x)/(a - x);
                d = x_max;
            }

            if (si(co) & 1)
            {
                e = y + (b - y) * (x_min - x)/(a - x);
                d = x_min;
            }

            if (co == c1)
            {
                x = d;
                y = e;
                c1 = computeCode(x_max, x_min, y_max, y_min, x, y);
            }
            else
            {
                a = d;
                b = e;
                c2 = computeCode(x_max, x_min, y_max, y_min, a, b);
            }
        }
    }
    if (flag)
    {
        cout<<"The line is clipped to ("<<x<<","<<y<<") and ("<<a<<","<<b<<")"<<endl;
    }
    else
    {
        cout<<"The line is outside of the viewing window\n";
    }
    return 0;
}

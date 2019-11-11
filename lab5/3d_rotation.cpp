#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int pts[3];
    cout<<"Enter the co-ordinate point: ";
    cin>>pts[0]>>pts[1]>>pts[2];
    double rot;
    int axis;
    cout<<"Enter the axis about which the point is to be rotated(0 for x-axis, 1 for y-axis, 2 for z-axis): "<<endl;
    cin>>axis;
    cout<<"Enter the angle of rotation: ";
    cin>>rot;
    int pr[3];
    int i=0;
    pr[axis] = pts[axis];
    pr[(axis+1)%3] = (pts[(axis+1)%3] * cos(rot)) + (pts[(axis+2)%3] * (-sin(rot)));
    pr[(axis+2)%3] = (pts[(axis+1)%3] * sin(rot)) + (pts[(axis+2)%3] * (cos(rot)));
    cout<<"Original point: ("<<pts[0]<<","<<pts[1]<<","<<pts[2]<<")"<<endl;
    cout<<"Rotated points: ("<<pr[0]<<","<<pr[1]<<","<<pr[2]<<")"<<endl;
    return 0;
}

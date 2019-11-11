#include<iostream>
using namespace std;

int main()
{
    int pts[3];
    cout<<"Enter the co-ordinate point: ";
    cin>>pts[0]>>pts[1]>>pts[2];
    int plane;
    cout<<"Enter the plane about which the point is to be reflected(0 for y-z, 1 for z-x, 2 for x-y): "<<endl;
    cin>>plane;
    int pr[3];
    int i=0;
    pr[plane] = -pts[plane];
    pr[(plane+1)%3] = pts[(plane+1)%3];
    pr[(plane+2)%3] = pts[(plane+2)%3];

    cout<<"Original point: ("<<pts[0]<<","<<pts[1]<<","<<pts[2]<<")"<<endl;
    cout<<"Rotated points: ("<<pr[0]<<","<<pr[1]<<","<<pr[2]<<")"<<endl;
    return 0;
}


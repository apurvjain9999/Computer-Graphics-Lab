#include<iostream>
using namespace std;

int main()
{
    int x,y,z;
    int tx,ty,tz;
    int xi,yi,zi;
    cout<<"Enter the co-ordinate point: ";
    cin>>x>>y>>z;
    cout<<"Enter x,y,z translation: ";
    cin>>tx>>ty>>tz;
    cout<<"Original point: ("<<x<<","<<y<<","<<z<<")"<<endl;
    xi = x + tx;
    yi = y + ty;
    zi = z + tz;
    cout<<"Translated point: ("<<xi<<","<<yi<<","<<zi<<")"<<endl;
    return 0;
}

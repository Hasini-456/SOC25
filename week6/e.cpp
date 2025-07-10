#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;

    int ax, ay;
    cin>>ax>>ay;

    int bx, by, cx, cy;
    cin>>bx>>by>>cx>>cy;

    if((min(bx, cx) < ax && ax < max(bx, cx)) || (min(by, cy) < ay && ay < max(by, cy))) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
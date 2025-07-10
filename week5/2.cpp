#include<iostream>

using namespace std;

int main(){
    int a, b, c;
    cin>>a>>b>>c;

    long long sum = 2*c;
    if(a == b || a == b-1 || b == a-1) sum = sum + a + b;
    else sum = sum + 2*min(a, b) + 1;

    cout<<sum<<endl;
}
#include<iostream>
using namespace std;

int main(){
    int t,n,a;
    cin>>t;
    while(t){
        t--;
        cin>>n;
        int b = 0;
        while(n){
            n--;
            cin>>a;
            b = b | a;
        }
        cout<<b<<endl;
    }
}
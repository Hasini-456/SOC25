#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,a,prev;
    long long int res;
    cin>>n;
    prev = -1; res = 0;
    for(int i=0; i<n; i++){
        cin>>a;
        if(a< prev){
            res = res + (prev - a);
            a = prev;
        }
        prev = a;
    }
    cout << res <<endl;
}
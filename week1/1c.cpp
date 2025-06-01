#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int T,N,max,a;
    cin>>T;
    for(int i=0; i<T; i++){
       cin>>N;
       max = 0;
       for(int i=0; i<N; i++){
           cin>>a;
           if(a > max) max = a;
       }
       cout<<max<<endl;
    }
}

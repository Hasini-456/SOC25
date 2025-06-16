#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    return b==0? a: gcd(b, a%b);
}

int main(){
    int t, l, r;
    cin>>t;
    while(t--){
        cin>>l>>r;
        
        int a = 0;

        if(l == r){
            for(int i=2; i<=sqrt(l); i++){
                if(l % i == 0){
                    cout<<i<<" "<<l-i<<endl;
                    a = 1;
                    break;
                }
            }
        }
        else{
            // l > r =>  a 2 multiple is there, gcd 2
            //if r<4, not possible
            if(r >= 4){
                if(r%2 == 0){
                    cout<<2<<" "<<r-2<<endl;
                }else{
                    cout<<2<<" "<<r-3<<endl;
                }
                a = 1;
            }
        }

        if( a == 0)cout<<-1<<endl;
    }
}
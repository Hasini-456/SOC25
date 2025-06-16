#include<bits/stdc++.h>
using namespace std;

int main(){
    long long m,n, t, moves;
    cin>>t;
    while(t--){
        cin>>m>>n;
        //max gcd is abs(m-n);
        //so have to find no.of moves
        if(m == n) cout<<0<<" "<<0<<endl;
        else{
            long long gcd = abs(m-n);
            long long rem = m % gcd;
            //we can either subtract rem times or add gcd-rem times
            if(m < rem || n < rem){
                moves = gcd-rem;
            }else{
                moves = min(rem, gcd-rem);
            }
            cout<<gcd<<" "<<moves<<endl;
        }
    }
}
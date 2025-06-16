#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    // if(a < b) return gcd(b, a);  //a >= b
    // else if(a%b == 0) return b;
    // else return gcd(a-b, b);
    return b == 0? a : gcd(b, a%b);
}

int main(){
    int t;
    long long n, sum; // wasted half an hour for using int instead of long long
    cin>>t;
    while(t--){
        cin>>n;
        sum = 0;
        long long temp  = n;
        while(temp){
            sum = sum + (temp % 10);
            temp = temp/10;    
        }
        
        while(true){
            if(gcd(n, sum) > 1) {
                cout<<n<<endl;
                break;
            }
            temp = n;
            while(temp > 0){
                if(temp%10 == 9){
                    sum = sum - 9;
                    temp = temp/10;
                }else{
                    break;
                }
            }
            n++;
            sum++;
        }
    }
}
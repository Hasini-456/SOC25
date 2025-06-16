#include<bits/stdc++.h>
using namespace std;

// int main(){
//     int n, a, b;
//     cin>>n;
//     while(n--){
//         cin>>a>>b;
//         int x = pow(10, 9)+7;
//         int t  = b;
//         long long y = 1;
//         //a^b modulo x------------if a^b < x, ans is a^b; else a^b > x
//         while(t--){
//             y = y*a;
//             if(y > x){
//                 y = y%x;
//             }
//         }
//         cout<< y<<endl;

//     }
// }

int main(){
    int n;
    long long a, b;
    int x = 1e9+7;

    cin>>n;
    while(n--){
        cin>>a>>b;

        long long res = 1;
        
        while(b > 0){   //main idea here is a^b modm = (a modm)^b modm AND a^b = a^2)^b/2
            if(b % 2 == 1){
                res = (res*a) % x;
            }
            a = (a * a) % x;
            b = b/2;
        }

        cout<<res<<endl;
    }
}


#include<bits/stdc++.h>
using namespace std;
// int gcd(int a, int b){
//     return b == 0? a : gcd(b, a%b);
// }

// int main(){
//     int n, x;
//     cin>>n;
//     vector<int> a;
//     int max = 0;
//     while(n--){
//         cin>>x;
//         if(a.size() == 0) a.push_back(x);
//         else{
//             for(int i=0; i < a.size(); i++){
//                 if(gcd(a[i], x) > max) max = gcd(a[i], x);
//             }
//             a.push_back(x);
//         }
//     }
//     cout<<max<<endl;
// }


//I didn't get the idea

const int MAX = 1e6+1;

int main(){
    vector<int> freq(MAX, 0);

    int n,x;
    cin>>n;
    while(n--){
        cin>>x;
        freq[x]++;
    }

    for(int g= MAX-1; g>= 1; g--){
        //checking whether g is that max common divisor
        //how we are checking?
        //for all g's through for loop, we are again gng through all multiples of g < MAX;
        //if that multiples of g count >= 2, then g is the answer, as we  are gng from largest to smallest
        int count = 0; //counts no.of multiples of g are in the vector
        for(int multiple = g;  multiple < MAX; multiple += g){
            count += freq[multiple]; //freq[x] = 0 if it is not in the input vector, so count wont increase
            if(count>= 2) break; //early break;
        }
        if(count >=2){
            cout<<g<<endl;
            break;
        }
    }
}
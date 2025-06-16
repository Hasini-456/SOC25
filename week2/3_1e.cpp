#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    return b == 0? a : gcd(b, a%b);
}

// int gcd_array(vector<int>& v){
//     if(v.size() == 1) return v[0];
//     else{
//         int g = gcd(v[0], v[1]);
//         for(int i=2; i<v.size(); i++){
//             g = gcd(g, v[i]);
//         }
//         return g;
//     }
// }

// int main() {
// 	// your code goes here
//     int t, n, x;
//     cin>>t;
//     while(t--){
//         cin>>n;
//         vector<int> v;
//         for(int i=0; i<n; i++){
//             cin>>x;
//             v.push_back(x);
//         }
        
//         int g = gcd_array(v);
        
//         vector<int> temp;
//         int count = 0;
        
//         if(g != 1){
//             count = n;
//         }else{
//             for(int i=0; i<n; i++){
//                 temp = v;
//                 temp.erase(temp.begin()+i);
//                 if(gcd_array(temp) != 1) count++;
//             }
//         }
//         cout<<count<<endl;
//     }
// }


int main(){
    int t, n, x;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> v;
        for(int i=0; i<n; i++){
            cin>>x;
            v.push_back(x);
        }
        //very imp and nice idea
        vector<int> pre_g;
        pre_g.push_back(v[0]);
        int prev;
        for(int i=1; i<n; i++){
            prev= pre_g.back();
            pre_g.push_back(gcd(prev, v[i]));
        }
        
        
        vector<int> suf_g;
        reverse(v.begin(), v.end());
        suf_g.push_back(v[0]);
        for(int i=1; i<n; i++){
            prev = suf_g.back();
            suf_g.push_back(gcd(prev, v[i]));
        }
        
        reverse(suf_g.begin(), suf_g.end());
        
        int g0 = pre_g[n-1];
        
        
        int count = 0;
        
        if(g0 > 1) count = n;
        else{
            //without index index i
            //pre_g[i-1], suf_g[i+1]
            for(int i=0; i<n; i++){
                if(i == 0){
                    if(suf_g[1] >1) count++;
                }else if( i == n-1){
                    if(pre_g[n-2] > 1) count++;
                }else{
                    if(gcd(suf_g[i+1], pre_g[i-1]) > 1) count++;
                }
            }
        }
        cout<<count<<endl;
    }
}
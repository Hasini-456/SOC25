#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main(){
    int t, m, n;
    cin>>t;
    while(t--){
        cin>>m>>n;

        vector<bool> is_prime(n+1, true);
        is_prime[0] = false;
        is_prime[1] = false;
        for(int i=2; i*i<n+1; i++){
            if(is_prime[i]){
                for(int j = max(i*i, (m/i)*i); j<=n; j += i){
                    is_prime[j] = false;
                }
            }
        }
        for(int i=m; i<= n; i++){
            if(is_prime[i]) cout<<i<<endl;
        }
        cout<<endl;
    }
}
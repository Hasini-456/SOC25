#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, k;
    cin>>n>>k;

    vector<bool> is_prime(n+1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for(int i=2; i*i<=n; i++){
        if(is_prime[i]){
            for(int j=i*i; j<=n; j+= i){
                is_prime[j] = false;
            }
        }
    }

    vector<int> primes;
    for(int i=0; i<=n; i++){
        if(is_prime[i]) primes.push_back(i);
    }
    int m = primes.size();
    int count = 0;
    int x;
    for(int i=0; i<m-1; i++){
        x = primes[i] + primes[i+1] + 1;
        if(x <= n){
            if(is_prime[x]) count++;
        }else{
            break;
        }
    }
    // primes.pop_back();
    if(count >= k) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
}
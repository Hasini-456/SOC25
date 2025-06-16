#include<iostream>
#include<vector>

using namespace std;
int main(){
    int n;
    cin>>n;
    //first locating primes < n
    vector<bool> is_prime(n+1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for(int i = 2; i*i<= n; i++){
        if(is_prime[i]){
            for(int j= i*i; j< n+1; j += i){
                is_prime[j] = false;
            }
        }
    }

    int count = 0;
    for(int i=2; i<=n; i++){
        int no_d = 0;
        for(int j =2; j<=i; j++){
            if(is_prime[j]){
                if(i%j == 0){
                    no_d++;
                    // if(is_prime[i/j] && j*j != i) no_d++;
                }
            }
            if(no_d > 2) break;
        }
        if(no_d == 2) count++;
    }
    cout<<count<<endl;
}
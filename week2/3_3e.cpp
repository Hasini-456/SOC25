#include<iostream>
#include<vector>

using namespace std;
int main(){
    //i+2 is pricei
    int n;
    cin>>n;
    //n >=1.
    //prices start from 2 to n+1

    vector<bool> is_prime(n+2, true);
    is_prime[0] = false;
    is_prime[1] = false;

    for(int i= 2; i*i< n+2; i++){
        if(is_prime[i]){
            for(int j= i*i; j<n+2; j += i){
                is_prime[j] = false;
            }
        }
    }

    vector<int> res(n, 1);
    int c = 1;
    for(int i=0; i<n; i++){
        if(!is_prime[i+2]){
            res[i] = 2; // for non-primes 2
            c = 2;
        } 
    }
    cout<<c<<endl;
    for(int i=0; i<n; i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}
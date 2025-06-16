#include<bits/stdc++.h>
using namespace std;
const int M= 1e9 + 7;

long long mod_power(long long a, long long exp){
    long long res = 1;
    // exp = exp%(M-1);
    while(exp > 0){
        if(exp%2 == 1) res = (res*a)%M;
        a = (a*a)%M;
        exp = exp/2;
    }
    return res;
}

long long mod_inverse(long long a){
    return mod_power(a, M-2);
}

int main(){
    int n;
    cin>>n;
    vector<int> primes; 
    vector<int> powers;
    long long N = 1; //number;
    
    long long a, x;
    long long num = 1;
    long long sum = 1;

    //pro = N^(num_divisors/2);
    //if num of divisors is odd, we have to do pro *= sqrt(N)
    //first preparing exp num_divisors/2;
    //for expo we have to do mod (M-1). so we are not taking directly from num
    long long exp = 1;

    for(int i=0; i<n; i++){
        cin>>a>>x;
        primes.push_back(a);
        powers.push_back(x);

        num = (num*(x+1))%M;
        long long term = (mod_power(a, x+1) - 1 + M)%M;
        //have to do term/(a-1)
        term = (term* mod_inverse(a-1))%M;
        sum = (sum*term)%M;

        exp = (exp * (x+1))%(2 *(M-1)); ////////////modulus 2*(M-1)

        N = (N * mod_power(a, x))%M;
    }
    
    long long pro = 1;
    long long exp2;
    //N = product of ai^xi; pro_i = ai^xi ^exp;  ai ^(xi ^ exp)
    for(int i=0; i<n; i++){
        a = primes[i];
        x = powers[i];
        exp2 = (x * exp) %(2*(M-1)); //////////this modulus 2*(M-1) is very veryimp, without 2 also u will get errors
        exp2 = exp2/2;
        pro = (pro*(mod_power(a, exp2)))%M;
    }    

    cout<<num<<" "<<sum<<" "<<pro<<endl;
}


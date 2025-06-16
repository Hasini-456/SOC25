#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

long long mod_power(long long a, long long exp, long long M){
    long long res = 1;
    // exp = exp%(M-1);
    while(exp > 0){
        if(exp%2 == 1) res = (res*a)%M;
        a = (a*a)%M;
        exp = exp/2;
    }
    return res;
}

long long mod_inverse(long long a, long long M){
    return mod_power(a, M-2, M);
}

vector<char> segmented_sieve(long long L, long long R){
    //generating all primes upto sqrt R
    long long lim = sqrt(R);
    vector<char> mark(lim+1, true);
    vector<long long> primes;
    for(long long i=2; i<= lim; i++){
        if(mark[i]){
            primes.push_back(i);
            for(long long j = i*i; j<= lim; j += i){
                mark[j] = false;
            }
        }
    }

    vector<char> is_prime(R-L+1, true);
    for(long long i: primes){
        for(long long j =max(i*i, (L+i-1)/i *i); j<=R; j+= i){
            is_prime[j-L] = false;
        }
    }

    if(L == 1) is_prime[0] = false;

    return is_prime;
}

int main(){
    int T,L,R;
    cin>>T;
    while(T--){
        cin>>L>>R;

        // vector<bool> is_prime(2*R, true);
        // is_prime[0] = false;
        // is_prime[1] = false;
        // for(int i=2; i*i< 2*R; i++){
        //     if(is_prime[i]){
        //         for(int j = i*i; j< 2*R; j += i){
        //             is_prime[j] = false;
        //         }
        //     }
        // }

        // vector<int> primes;
        // for(int i=L; i<=R; i++){
        //     if(is_prime[i]){
        //         primes.push_back(i);
        //     }
        // }
        // for(int i = R+1; i< 2*R; i++){
        //     if(is_prime[i]) {primes.push_back(i); break;}
        // }

        vector<char> isprime = segmented_sieve(L, 2*R);
        vector<int> primes;

        for(int i=L; i<= R; i++){
            if(isprime[i-L]) primes.push_back(i);
        }
        for(int i= R+1; i<= 2*R; i++){
            if(isprime[i-L]){
                primes.push_back(i);
                break;
            }
        }


        long long S=0;
        long long x;
        long long a;
        int p1, p2;
        for(int i=0; i<primes.size()-1; i++){
            p1 = primes[i];
            p2 = primes[i+1];
            if(p1 == 3) continue;
            else{
                //finding no.of digits
                long long n=10;
                while(true){
                    if(p1/n == 0) break;
                    else{
                        n = n*10;
                    }
                }

                //p1+n*a = b*p2;
                // n*a mod p2 = p2 -p1
                // a = n^(-1) * p2-p1 mod p2
                //inv_n = modular inverse of n mod p2
                long long inv_n = mod_inverse(n , p2)%p2;
                a = ((p2-p1)*inv_n)%p2;
                x = p1 + n*a;
                S += x;
            }
        }
        cout<<S<<endl;
    }
}
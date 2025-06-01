#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int T;
    long long int N, n;
    int j, k;
    int l, r;
    int res;
    cin>>T;
    for(int i=0; i<T; i++){
        cin>>N;
        if (N == 1) {
            cout << 2 << endl;
            continue;
        }
        if (N == 2) {
            cout << 1 << endl;
            continue;
        }
        if (N == 3) {
            cout << 0 << endl;
            continue;
        }
        res = 0;
        j =0;
        //finding smallest j such that N < 2^j
        while((1LL << j) < N) j++;
        n = N - (1LL << j-1);
        //have to find nearest 2th power to n
        if(n == (1LL << (j-1))) res = 1;
        else if( n == 0) res = 1;
        else{
            k = 0;
            while((1LL << k) < n) k++;
            if(k == j-1){
                l = n - (1LL << (k-1));
                r = (1LL << k) - n;
                if(r < l) res = r+1;
                else res =l;
            }else{
                l = n - (1LL << (k-1));
                r = (1LL << k) - n;
                if(l < r) res = l;
                else res= r;
            }
            
        }
        cout<<res<<endl;
    }
}

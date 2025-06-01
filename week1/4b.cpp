#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int N,T,K, a, max, sum;
    cin>>T;
    for(int i=0; i<T; i++){
        cin>>N>>K;
        vector<int> v;
        for(int j=0; j<N; j++){
            cin>>a;
            v.push_back(a);
        }
        sum = 0;
        for(int j=0; j<K; j++){
            sum = sum+v[j];
        }
        max = sum;
        for(int j=K; j<N; j++){
            sum = sum + v[j]-v[j-K];
            if(sum > max) max = sum;
        }
        cout<<max<<endl;
    }
}

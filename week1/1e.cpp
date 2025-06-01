#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int T, N, a,max;
    cin>>T;
    for(int i=0; i<T; i++){
        cin>>N;
        unordered_map<int, int> m;
        for(int j=0; j<N; j++){
            cin>>a;
            m[a] += 1;
        }
        max = 0;
        for(const auto& pair : m){
            if(pair.second > max) max =  pair.second;
        }
        cout<< N-max <<endl;
    }
}

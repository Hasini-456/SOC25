#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int T, N, a;
    cin>>T;
    for(int i=0; i<T; i++){
        cin>>N;
        unordered_map<int, int> m;
        for(int j=0; j< 2*N; j++){
            cin>>a;
            m[a] += 1;
        }
        int count = 0;
        for(const auto& pair : m){
            if(pair.second != 1) count++;
        }
        cout<<count<<endl;
    }
}

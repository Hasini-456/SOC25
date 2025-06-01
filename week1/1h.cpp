#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T,N,a;
    cin>>T;
    for(int i=0; i<T; i++){
        cin>>N;
        unordered_set<int> s;
        for(int i=0; i<N; i++){
            cin>>a;
            if(s.find(a) == s.end()) s.insert(a);
            else s.erase(a);
        }
        for(const auto& it: s){
            cout<<it << endl;
        }
    }
}

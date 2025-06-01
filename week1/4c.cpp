#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int T, N, B, a;
    cin>>T;
    for(int i=0; i<T; i++){
        cin>>N>>B;
        multiset<int> s; 
        for(int j=0; j<N; j++){
            cin>>a;
            s.insert(a);
        }
        a = 0;
        for(auto it: s){
            if(s.find(it + B) != s.end()){
                a = 1;
                break;
            }
        }
        cout<<a<<endl;
    }
}

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int T, N;
    int a, prev;
    cin>>T;
    for(int i =0; i< T; i++){
        cin>>N;
        prev = 0;
        vector<int> v;
        for(int j =0; j<N; j++){
            cin>>a;
            if(a != prev){
                v.push_back(a);
                prev = a;
            }
        }
        a = v.size();
        cout<<a<<endl;
        for(int j=0; j<a; j++){
            cout<<v[j]<<" ";
        }
        cout<<endl;
    }
}

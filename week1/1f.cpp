#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int T,n, a;
    cin>>T;
    for(int i=0; i<T; i++){
        cin>>n;
        set<int> s;
        for(int i=0; i<n; i++){
            cin>>a;
            s.insert(a);
        }
        cout<<s.size()<<endl;
    }
}

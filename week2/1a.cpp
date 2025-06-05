#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        string o;
        cin>>s;
        // your code goes here
        for(int i=0; i<n-1; i=i+2){
            if(s[i] == '0' && s[i+1] == '0') o.append("A");
            else if(s[i] == '0' && s[i+1] == '1') o.append("T");
            else if(s[i] == '1' && s[i+1] == '0') o.append("C");
            else o.append("G");
        }
        cout<<o<<endl;
    }

}

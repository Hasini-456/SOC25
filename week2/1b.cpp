#include<bits/stdc++.h>
using namespace std;
int main(){
    string s; 
    int n;
    cin>>n;
    cin>>s;
    int x = -1;
    for(int i=0; i<n-1; i++){
        if(s[i] > s[i+1]){
            cout<<"YES"<<endl;
            cout<<i+1<<" "<<i+2<<endl;
            x = 0;
            break;
        }
    }
    if(x == -1) cout<<"NO"<<endl;
}
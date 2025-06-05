#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    string s;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>s;
        int j = 0;
        int count = 0;
        int i=0;
        while(i < n){
            if(s[i] == '('){
                j++; i++;
            } 
            else{
                j--;
                if( j<0){
                    s.erase(i, 1);
                    s.push_back(')');
                    j++;
                    count++;
                }else{
                    i++;
                }
            }
        }
        cout<<count<<endl;
    }
}
#include<iostream>
using namespace std;

int main(){
    int n;
    string s;
    cin>>n>>s;

    int l, r;
    l = r = 0;
    for(int i=0; i<n; i++){
        if(s[i] == 'L') l++;
        else r++;
    }
    cout<<l+r+1<<endl;
}
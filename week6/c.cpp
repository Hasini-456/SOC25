#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, t;
    cin>>n>>t;
    vector<int> v(n);
    for(int i=1; i<n; i++){
        cin>>v[i];
    }
    int temp = 1;
    int pos = 0;
    while(temp<n){
        temp = temp + v[temp];
        if(temp == t){
            pos = 1;
            break;
        }
    }
    if(pos) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
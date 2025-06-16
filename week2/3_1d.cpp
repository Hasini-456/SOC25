#include<bits/stdc++.h>
using namespace std;

int main(){
    int q, n, k;
    int x;
    cin>>q;
    while(q--){
        cin>>n>>k;
        vector<int> v;
        for(int i=0; i< n; i++){
            cin>>x;
            v.push_back(x);
        }

        sort(v.begin(), v.end());
        if(v[n-1]-v[0] > 2*k){
            cout<<-1<<endl;
        }else{
            cout<<v[0]+k<<endl;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, a;
    vector<int> p;
    vector<int> ne;
    vector<int> z;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>a;
        if(a>0) p.push_back(a);
        else if(a<0) ne.push_back(a);
        else z.push_back(a);
    }
    vector<int> sn;
    vector<int> sp;
    vector<int> sz;
    while(!z.empty()){
        a = z.back();
        z.pop_back();
        sz.push_back(a);
    }
    a = ne.back();
    ne.pop_back();
    sn.push_back(a);
    while(!p.empty()){
        a = p.back(); 
        p.pop_back();
        sp.push_back(a);
    }
    if(sp.empty()){
        a = ne.back();
        ne.pop_back();
        sp.push_back(a);
        a = ne.back();
        ne.pop_back();
        sp.push_back(a);
    }
    while(!ne.empty()){
        a = ne.back();
        ne.pop_back();
        sz.push_back(a);
    }
    
    cout<<sn.size()<<endl;
    for(int i=0; i<sn.size(); i++){
        cout<<sn[i]<<" ";
    }
    cout<<endl;
    cout<<sp.size()<<endl;
    for(int i=0; i<sp.size(); i++){
        cout<<sp[i]<<" ";
    }
    cout<<endl;
    cout<<sz.size()<<endl;
    for(int i=0; i<sz.size(); i++){
        cout<<sz[i]<<" ";
    }
    cout<<endl;


}
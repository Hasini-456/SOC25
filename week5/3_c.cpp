#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long ll;

ll dist(pair<int, int> a, pair<int, int> b){
    return abs((ll)a.first-b.first)+abs((ll)a.second-b.second);
}

int main(){
    int t;
    cin>>t;
    int n, k, a, b;
    while(t){
        t--;
        cin>>n>>k>>a>>b;
        a--; b--; //changing to zero index

        vector<pair<int, int>> coords(n);
        
        for(int i=0; i<n; i++){
            cin>>coords[i].first>>coords[i].second;
        }

        //direct cost from a to b
        ll direct = dist(coords[a], coords[b]);

        if(k == 0){
             cout<<direct<<endl;
             continue;
        }

        //min cost from a , b to any major city;
        ll minA = LLONG_MAX;//imp
        ll minB = LLONG_MAX;//imp
        
        for(int i=0; i<k; i++){
            minA = min(minA, dist(coords[a], coords[i]));
            minB = min(minB, dist(coords[b], coords[i]));
        }

        ll result = min(direct, minA+minB);
        cout<<result<<endl;

    }
}
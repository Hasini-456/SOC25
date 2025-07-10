#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    int w, h;
    int k;
    int x, y;
    long long a1, a2;
    while(t){
        t--;
        cin>>w>>h;

        cin>>k;
        vector<int> X1; 
        while(k){
            cin>>x;
            X1.push_back(x);
            k--;
        }

        cin>>k;
        vector<int> X2; 
        while(k){
            cin>>x;
            X2.push_back(x);
            k--;
        }

        cin>>k;
        vector<int> Y1;
        while(k){
            cin>>y;
            Y1.push_back(y);
            k--;
        }

        cin>>k;
        vector<int> Y2; 
        while(k){
            cin>>y;
            Y2.push_back(y);
            k--;
        }

        a1 = 1LL* h * max(X1.back()-X1[0], X2.back()-X2[0]);
        a2 = 1LL* w * max(Y1.back()-Y1[0], Y2.back()-Y2[0]);

        long long area = max(a1, a2);
        cout<<area<<endl;
    }
}
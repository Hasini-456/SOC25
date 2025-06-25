#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t, n, k;
    cin>>t;
    int a;
    int mod = 1e9 + 7;
    while(t){
        t--;
        cin>>n>>k;
        
        long long res = 1;
        //ans is n^k;
        for(int i=0; i<k; i++){
            res *= n;
            res = res%mod;
        }
        cout<<res<<endl;
    }
}
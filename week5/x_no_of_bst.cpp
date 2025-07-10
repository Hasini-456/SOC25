#include<iostream>
#include<vector>

using namespace std;

const int mod = 1e8 + 7;
int main(){
    int t;
    cin>>t;
    vector<int> v(t);
    int max_n = 0;
    for(int i=0; i<n; i++){
        cin>>v[i];
        max_n = max(max_n, v[i]);
    }
    
    vector<long long> catalan(max_n+1, 0); //catalan[i] = no.of binary trees with i numbers----anything can be the root from 1 to i 
    catalan[0] = 1;                        
    if(max_n>=1) catalan[1] = 1;
    
    for(int n=2; n<= max_n; n++){
        for(int i=0; i<n; i++){
            //i+1 as root----so first i numbers in left subtree, remaining n-1-i in right subtree
            catalan[n] = (catalan[n] + catalan[i]*catalan[n-1-i])%mod;
        }
    }

    for(int i : v){
        cout<<catalan[i]<<endl;
    }
}
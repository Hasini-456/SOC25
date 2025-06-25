#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t,n,a;
    cin>>t;
    while(t){
        t--;
        cin>>n;
        vector<vector<int>> M(n, vector<int>(n, 0));
        int x;
        vector<int> res;
        bool valid = true;

        for(int i=0; i<n; i++){
            x = (1<<30) - 1;
            for(int j=0; j<n; j++){
                cin>>a;
                M[i][j] = a;
                if(i != j) {
                    x = x & a;
                }
            }     
            res.push_back(x);
        }


        for(int i=0; i<n && valid; i++){
            for(int j=0; j<n && valid; j++){
                if(i != j && (M[i][j] != (res[i] | res[j]))){
                    valid = false;
                    // break;
                }
            }
        }
        if(valid){
            cout<<"Yes"<<endl;
            for(int i=0; i<n; i++){
                cout<<res[i]<<" ";
            }
            cout<<endl;
        }else{
            cout<<"No"<<endl;
        }
        

    }
}
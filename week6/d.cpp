#include <iostream>
#include <vector>

using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> p(n+1);
    for(int i=1; i<=n; i++){
        cin>>p[i];
    }

    int a;
    for(int i=1; i<=n; i++){
        vector<int> h(n+1);
        a = i;
        while(true){
            if(h[a] == 1) break;
            h[a]++;
            a = p[a];
        }
        cout<<a<<" ";
    }
    cout<<endl;
}
#include<iostream>

using namespace std;

int main(){
    int n, m;
    cin>>n>>m;

    int t = n;
    int s = m;
    while(t--){
        s = s/2;
        if(s == 0) break;
    }

    if(s == 0) cout<< m<<endl;
    else{
        t = n;
        int x = 1;
        while(n--){
            x = x*2;
        }
        cout<< m%x<<endl;
    }
}                                                                                                         
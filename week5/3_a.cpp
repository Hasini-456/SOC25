#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin>>t;

    int a, b, c, d;
    while(t){
        t--;
        cin>>a>>b>>c>>d;
        
        if(d < b) cout<<-1<<endl;
        else{
            int x = d-b;
            if(a+x < c) cout<<-1<<endl;
            else{
                int y = a+x-c;
                cout<<x+y<<endl;
            }
        }
    }
}
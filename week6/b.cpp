#include <iostream>
#include <vector>
using namespace std;

int main(){
    int r, c;
    cin>>r>>c;
    string str;
    vector<string> v(r);
    for(int i=0; i<r; i++){
        cin>>v[i];
    }
    
    int x = 1;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(v[i][j] == 'S'){
                if(j > 0) {
                    if(v[i][j-1] == 'W'){
                        //ans is NO
                        x = 0;
                        break;
                    }else if(v[i][j-1] == '.'){
                        v[i][j-1] = 'D';
                    }
                }

                if(j < c-1){
                    if(v[i][j+1] == 'W'){
                        //ans is NO
                        x = 0;
                        break;
                    }else if(v[i][j+1] == '.'){
                        v[i][j+1] = 'D';
                    }
                }

                if(i > 0) {
                    if(v[i-1][j] == 'W'){
                        //ans is NO
                        x = 0;
                        break;
                    }else if(v[i-1][j] == '.'){
                        v[i-1][j] = 'D';
                    }
                }

                if(i < r-1){
                    if(v[i+1][j] == 'W'){
                        //ans is NO
                        x = 0;
                        break;
                    }else if(v[i+1][j] == '.'){
                        v[i+1][j] = 'D';
                    }
                }
            }
        }
        if(x == 0) break;
    }

    if(x == 0){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
        for(int i=0; i<r; i++){
            cout<<v[i]<<endl;
        }
    }
}
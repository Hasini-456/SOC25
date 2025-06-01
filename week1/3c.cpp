#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int N, Q,a,b;
    cin>>N>>Q;
    unordered_map<int, int> signs;
    vector<int> roots;
    for(int i=0; i< N; i++){
        cin>>a;
        roots.push_back(a);
    }
    sort(roots.begin(), roots.end());
    
    if(N&2 == 0) b=0;
    else b=1;
    
    for(int i=0; i< N; i++){
        signs[roots[i]] = (b+1+i)%2;
    }
    
    int start, middle, end;
    string result;
    int c ;
    for(int i=0; i<Q; i++){
        cin>>a;
        c = 0;
        start = 0;
        end = N-1;
        while(start<=end){
            middle = (start+end)/2;
            if(roots[middle] > a) end = middle-1;
            else if(roots[middle] <a) start = middle+1;
            else{
                c =1;
                result = "0";
                break;
            }
        }
        if(c == 0){
            //start is index of smallest no greater than a
            //end is index of largest no smaller than a
            if(end == -1){
                if(b == 1) result = "POSITIVE";
                else result = "NEGATIVE";
            }
            else if(signs[roots[end]] == 1) result = "POSITIVE";
            else result = "NEGATIVE";
        }
        cout<<result<<endl;
    }
}
    
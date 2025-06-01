#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int T;
    long long int N;
    long long int start, end, middle, answer;
    cin>>T;
    long long int j;
    for(int i=0; i<T; i++){
        cin>>N;
        j = 1;
        while(j*(j+1) < 2*N) {j = j*2;}
        start = j/2;
        end = j;
        while(start <= end){
            middle = (start +end)/2;
            if(middle*(middle+1) > 2*N){
                end = middle-1;
            }else{
                answer = middle;
                start = middle+1;
            }
        }
        cout<<answer<<endl;
    }
}

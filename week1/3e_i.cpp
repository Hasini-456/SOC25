#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, N,H, a, max;
	int start, middle, end, sum;
	cin>>T;
	for(int i=0; i<T; i++){
	    cin>>N>>H;
	    vector<int> v;
	    max = 0;
	    for(int j=0; j< N; j++){
	        cin>>a;
	        if(a > max) max = a;
	        v.push_back(a-1);
	    }
	    //binary search for k btw 1 and max, have to find min k sucht that sigma v[i]/k <= H-N;
	    start = 1; 
	    end = max;
	    while(start <= end){
	        sum = 0;
	        middle = (start+end)/2;
	        for(int i=0; i<N; i++){
	            sum = sum+ v[i]/middle;
	        }
	        if(sum  > H-N) start = middle+1;
	        else end = middle-1;
	    }
	    //k = start
	    cout<<start<<endl;
	}
    
}

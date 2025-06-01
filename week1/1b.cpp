#include <bits/stdc++.h>
using namespace std;

int main() {
    int no_tcases, n, num;
    // int found = 0;

	// your code goes here
	cin>> no_tcases;
	for(int i=0; i<no_tcases; i++){
	    cin>>n;
	   // vector<int> vec;
	    unordered_map<int, int> arr;
	    for(int j=0; j<n; j++){
	        cin>> num;
	        if(arr.find(num) != arr.end()){
	            //it is already in arr, so increase its frequency by 1
	            arr[num]++;
	        }else{
	            arr.insert({num, 1});
	        }
	    }
	    
	    int maxFreq = 0;
	    int countMaxFreq = 0;
	    for(const auto& [key, value] : arr){
	        if(value > maxFreq){
	            maxFreq = value;
	            countMaxFreq = 1;
	        }else if(value == maxFreq){
	            countMaxFreq++;
	        }
	    }
	    if(countMaxFreq == 1) cout<<"YES"<<endl;
	    else cout<<"NO"<<endl;
	    
	}
	

}

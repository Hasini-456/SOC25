 #include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int T, N, Q,l, k, a, b;
    long long pre_sum;
    int temp;
    int start, middle, end;
    cin>>T;
    for(int i=0; i<T; i++){
        cin>>N>>Q;
        vector<int> v;
        
        for(int j=0; j<N; j++){
            cin>>l;
            v.push_back(l);
            
        }
        sort(v.begin(), v.end());
        
        vector<long long> pre;
        pre_sum = 0;
        pre.push_back(pre_sum); //this is imp
        for(int j=0; j<N; j++){
            pre_sum = pre_sum+v[j];
            pre.push_back(pre_sum);
        }
        for(int y=0; y<Q; y++){
            cin>>k;
            //finding from ehich index snakes have length greater than or equal to k
            //binary search
            start = 0; 
            end = N-1;
            while(start <= end){
                middle = (start + end)/2;
                if(v[middle] < k) start = middle+1;
                else end = middle-1;
            }
            //from start >= k
            //until end, less than k 
            //so i will find how many of these can be made k
            // a = N - start;
            // b = start;
            int j = start-1;
            // while(b > 0 && j>= 0){
            //     temp = k - v[j];
            //     if(temp < b){
            //         a = a+1;
            //         b = b - temp-1;
            //     }else{
            //         break;
            //     }
            //     if(j > 0) j--;
            // }
            // cout<<a<<endl;
            //-----------------TLE------------------
            
            //smallest x such that x+1 >=k- v[x+1]+..........+k-v[j], then a = a+j-x; cout a;
            // x+1>= k*(j-x) -(pre[j+1] - pre[x+1]), cout  n-x-1,
            //so smallest x s.t x >= k*(start-x) -(pre[start]-pre[x]), cout n-x
            
            start = 0;
            end = j+1;
            int x = j+1;
            while(start <= end){
                middle = (start+end)/2;
                int len = j+1-middle;
                long long sum = pre[j+1] - pre[middle];
                if((long long)k*len - sum > middle){
                    start = middle+1;
                }else{
                    x = middle;
                    end= middle-1;
                }
            }
            a = N-x;
            cout<<a<<endl;
        }
        
    }
}
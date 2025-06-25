class Solution {
public:
    vector<int> countBits(int n) {
        if(n == 0) return {0};
        if(n == 1) return {0,1};
        if(n == 2) return {0,1,1};
        //now n>2
        vector<int> res(n+1,0);
        res[1] =1 ;
        int t_pwr = 2;
        for(int i=2; i<n+1; i++){
            if(i >= 2*t_pwr) t_pwr = 2*t_pwr;
            res[i] = res[i-t_pwr]+1;
        }
        return res;
    }
};
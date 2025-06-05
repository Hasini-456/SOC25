class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> temp;
        int m;
        res.push_back({nums[0]});
        for(int i=1; i<n; i++){
            m = res.size();
            for(int j =0; j< m; j++){
                temp = res[0];
                res.erase(res.begin());
                for(int k = 0; k<=i ;k++){
                    temp.insert(temp.begin()+k, nums[i]);
                    res.push_back(temp);
                    temp.erase(temp.begin()+k);
                }
            }
        }
        return res;
    }
};
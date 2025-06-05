class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> subsets;
        subsets.push_back({});
        vector<int> temp;
        int m;
        for(int i=0; i<n; i++){
            m = subsets.size();
            for(int j=0; j<m; j++){
                temp = subsets[j];
                temp.push_back(nums[i]);
                subsets.push_back(temp);
            }
        }
        return subsets;
    }
};
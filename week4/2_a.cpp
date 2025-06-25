class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // int n = nums.size();
        // for(int i=0; i<n; i = i+2){
        //     if(i == n-1){
        //         return nums[i];
        //     }
        //     else if(nums[i] != nums[i+1]){
        //         return nums[i];
        //     }
        // }
        // return -1;

        //XOR operator

        int temp = nums[0];
        for(int i=1; i<nums.size(); i++){
            temp ^= nums[i];
        }
        return temp;
    }
};
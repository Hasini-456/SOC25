class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int start = 0;
            int end = nums.size();
            int middle;
            while(start < end){
                middle = (start+end)/2;
                if(nums[middle] > target) end = middle;
                else if(nums[middle] < target) start = middle+1;
                else return middle;
            }
            return -1;
        }
    };
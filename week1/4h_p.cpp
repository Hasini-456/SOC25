class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            std::sort(nums.begin(), nums.end());
            std::vector<std::vector<int>> foursums;
            int n = nums.size();
            int x, left, right;
            int long long sum;
            for(int i=0; i<n-3; i++){
                x = nums[i];
                if(i > 0 && nums[i] == nums[i-1]) continue;
                for(int j = i+1; j< n-2; j++){
                    left = j+1;
                    right = n-1;
                    if(j > i+1 && nums[j] == nums[j-1]) continue;
                    while(left < right){
                        sum = (long long) x+nums[j]+nums[left]+nums[right];
                        if(sum > target) right--;
                        else if(sum < target) left++;
                        else{
                            foursums.push_back({x, nums[j], nums[left], nums[right]});
                            while(left < right && nums[left] == nums[left+1]) left++;
                            while(left< right && nums[right] == nums[right-1]) right--;
                            left++;
                            right--;
                        }
                    }
                    
                }
            }
            return foursums;
        }
    };
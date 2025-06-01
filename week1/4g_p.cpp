class Solution {
    public:
        // int binarySearch(vector<int>& nums, int num){
        //     int start = 0;
        //     int end  = nums.size();
        //     int middle;
        //     while(start< end){
        //         middle = (start+end)/2;
        //         if(nums[middle] < num) {
        //             start = middle+1;
        //         }else if(nums[middle] > num){
        //             end = middle;
        //         }else{
        //             return middle;
        //         }
        //     }
        //     return -1;
        // }
        // vector<vector<int>> twoSum(vector<int>& nums,int sum){
        //     int n = nums.size();
        //     std::vector<std::vector<int>> twosums;
        //     for(int i = 0; i < n-1; i++){
        //         std::vector<int> sub(nums.begin()+i+1, nums.end());
        //         int x = binarySearch(sub, sum-nums[i]);
        //         if(x != -1){
        //             twosums.push_back({nums[i], sub[x]});
        //         }
        //     }
        //     return twosums;
        // }
        vector<vector<int>> threeSum(vector<int>& nums) {
            int n = nums.size();
            std::vector<std::vector<int>> threesums;
            std::sort(nums.begin(), nums.end());
            int left, right, sum;
            for(int i=0; i<n-1; i++){
                if(nums[i] > 0) break;
                if (i > 0 && nums[i] == nums[i - 1]) continue;// addec after getting duplicates
                // std::vector<int> sub(nums.begin()+i+1, nums.end());
                // std::vector<std::vector<int>> twosums = twoSum(sub, -nums[i]);
                
                // if(!twosums.empty()){
                //     for(const auto& vec: twosums){
                //         std::vector<int> temp;
                //         temp.push_back(nums[i]);
                //         temp.insert(temp.end(), vec.begin(), vec.end());
                //         threesums.push_back(temp);
                //     }
                // }
                left = i+1;
                right = n-1;
                //doing binarySearch is most efficient way, like 2 pointers
                while(left < right){
                    sum = nums[i]+nums[left]+nums[right];
                    if(sum > 0){
                        right--;
                    }else if (sum < 0){
                        left++;
                    }else{
                        threesums.push_back({nums[i], nums[left], nums[right]});
                        while(left < right && nums[left] == nums[left+1]) left++; //handling duplicates
                        while(left < right && nums[right]== nums[right-1]) right--; //handling duplicates
                        left++;
                        right--;
                    }
                }
                
            }
            return threesums;
        }
    };
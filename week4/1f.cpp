class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // int n = nums.size();
        // priority_queue<int> pq;
        // for(auto& i: nums) pq.push(i);
        // k--;
        // while(k){
        //     k--;
        //     pq.pop();
        // }
        // return pq.top();
        int min = 1e4;
        int max = -1e4;
        for(auto& i: nums){
            if(i < min) min = i;
            if(i > max) max = i;
        }
        vector<int> v(max-min+1, 0);
        for(auto& i : nums){
            v[i-min]++;
        }
        for(int i = max; i>= min; i--){
            k = k - v[i-min];
            if(k <= 0) return i;
        }
        return -1;
    }
};
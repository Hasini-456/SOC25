class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> res(n1, -1);

        unordered_map<int, int> mn2;
        // for(int i=0; i<n2; i++){
        //     mn2[nums2[i]] = i;
        // }

        stack<int> s;
        vector<int> storing(n2, -1);
        for(int i=0; i<n2; i++){
            mn2[nums2[i]] = i;
            while(!s.empty() && nums2[s.top()] < nums2[i]){
                int j  = s.top();
                storing[j] = nums2[i];
                s.pop();
            }
            s.push(i);
        }

        for(int i=0; i<n1; i++){
            res[i] = storing[mn2[nums1[i]]];
        }
        
        return res;
    }
};
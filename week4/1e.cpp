class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;

        unordered_map<int, int> n_f;
        for(auto i: nums){
            n_f[i]++;
        }

        // unordered_map<int, vector<int>> f_n;
        // for(auto pair : n_f){
        //     f_n[pair.second].push_back(pair.first);
        // }
        // int count = k;
        // for(int i = nums.size(); i>0; i--){
        //     // if(!f_n[i].empty()){    
        //         while(!f_n[i].empty() && k > 0){
        //             res.push_back(f_n[i].back());
        //             f_n[i].pop_back();
        //             k--;
        //         }
        //         if(k == 0) break;
        //     // } 
        // }
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            function<bool(pair<int, int>, pair<int, int>)>
        >pq(
            [](pair<int, int> a, pair<int, int> b){
                return a.second < b.second; //b should come before a // max heap
            }
        );
        
        for(auto& pair: n_f){
            pq.push(pair);
        }
        while(k){
            auto pair = pq.top();
            res.push_back(pair.first);
            pq.pop();
            k--;
        }
        return res;
    }
};
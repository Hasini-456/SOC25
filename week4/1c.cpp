class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);


        // for(int i=0; i<n; i++){
        //     int j = i+1;
        //     int temp = temperatures[i];
        //     while(j < n && temperatures[j] <= temp){
        //         j++;
        //     }
        //     if(j != n) res[i] = j-i;
        // }

//very good idea of using stack
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                int j = st.top();
                res[j] = i-j;
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();

        vector<int> res;

        unordered_map<char, int> mp;
        for(int i=0; i<m; i++){
            mp[p[i]]++;
        }

        int j =0;
        unordered_map<char, int> ms = mp;

        for(int i=0; i<n; i++){
            if(ms.find(s[i]) != ms.end()){
                if(ms[s[i]] > 0){
                    ms[s[i]]--;
                    j++;
                    if(j == m) {res.push_back(i-m+1); j--; ms[s[i-m+1]]++;}
                }else if(s[i] != s[i-j]){ //gng until the point where s[i] equal to smtg before, without just jumpimg j to 0
                    while(s[i] != s[i-j]){
                        ms[s[i-j]]++;
                        j--;
                    }
                    i--;
                }
            }else{
                j = 0;
                ms = mp;
            }
        }
        return res;
    }
};
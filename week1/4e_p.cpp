class Solution {
    public:
        string longestPalindrome(string s) {
            int n = s.size();
            if(n == 0) return "";
    
            std::vector<std::vector<bool>>  dp(n, std::vector<bool>(n, false));
            int start = 0;
            int maxlen = 1;
            
            for(int i = 0; i< n; i++){
                dp[i][i] = true;
            }
            for(int i=0;i<n-1;i++){
                if(s[i]==s[i+1]){
                    dp[i][i+1] = true;
                    start = i;
                    maxlen = 2;
                } 
    
            }
            for(int len = 3; len<=n ;len++){
                for(int j = 0; j<=n-len; j++){
                    if(s[j] == s[j+len-1] && dp[j+1][j+len-2]){
                        dp[j][j+len-1] = true;
                        start = j;
                        maxlen = len;
                    }
                }
            }
            return(s.substr(start, maxlen));
    
        }
    };
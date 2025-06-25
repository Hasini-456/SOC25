class Solution {
public:
    int calculate(string s) {
        stack<int> a;
        int n = s.length();
        for(int i=0; i<n; i++){
            if(s[i] == ' ') continue;
            else if(!(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')){
                int sum = s[i]-'0';
                int j = i+1;
                while(s[j]-'0' >= 0 && s[j]-'0' <= 9){
                    sum = sum*10;
                    sum = sum + (s[j] - '0');
                    j++;
                }
                i = j-1;
                a.push(sum);
            }else if(s[i] == '*' || s[i] == '/'){
                int x = a.top();
                a.pop();
                int j = i+1;
                while(s[j] == ' ' && j<n)j++;
                if(j == n) continue;
                int sum = 0;
                while(s[j]-'0' >= 0 && s[j]-'0' <= 9){
                    sum = sum*10;
                    sum = sum + (s[j] - '0');
                    j++;
                }
                if(s[i] == '*') a.push(x*(sum));
                else if(s[i] == '/') a.push(x/(sum));
                i = j-1;
            }else if(s[i] == '-'){
                int j = i+1;
                while(s[j] == ' ' && j<n)j++;
                if(j == n) continue;
                int sum = 0;
                while(s[j]-'0' >= 0 && s[j]-'0' <= 9){
                    sum = sum*10;
                    sum = sum + (s[j] - '0');
                    j++;
                }
                a.push(-1*(sum));
                i = j-1;
            }
        }
        int res = 0;
        while(!a.empty()){
            res+= a.top();
            a.pop();
        }
        return res;
    }
};
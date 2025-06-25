class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> nums;
        int a;
        int b;
        for(int i=0; i<n; i++){
            string x = tokens[i];
            if(!(x == "+" || x == "-" || x == "*" || x == "/")){
                nums.push(stoi(x));
            }else{
                a = nums.top();
                nums.pop();
                b = nums.top();
                nums.pop();
                if(x == "+"){
                    nums.push(a+b);
                }else if(x == "-"){
                    nums.push(b-a);
                }else if(x == "*"){
                    nums.push(b*a);
                }else{
                    nums.push(b/a);
                }
            }
        }
        return nums.top();
    }
};
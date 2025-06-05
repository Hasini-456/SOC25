#include <bits/stdc++.h>
using namespace std;

string multiply(string num, int x){
    int carry = 0;
    string res = "";
    
    int digit, prod;
    
    for(int i=num.length()-1; i>=0; i--){
        digit = num[i] - '0';
        prod = digit*x + carry;
        res += (prod%10)+'0';
        carry = prod/10;
    }
    
    while(carry > 0){
        res += (carry%10) + '0';
        carry = carry/10;
    }
    
    reverse(res.begin(), res.end());
    return res;
    
}

int main() {
	// your code goes here
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        string fact = "1";
        for(int i=2; i<=n; i++){
            fact = multiply(fact, i);
        }
        cout<<fact<<endl;
    }
}

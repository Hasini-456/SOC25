class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string res;
        string word;
        for(int i=0; i<s.length(); i++){
            if(i == s.length()-1 && s[i] != ' '){
                // word.push_back(s[i]);
                word += s[i];
                words.push_back(word);
            }
            else if(s[i] != ' '){
                // word.push_back(s[i]);
                word += s[i];
            } 
            else{
                if(!word.empty()){
                    words.push_back(word);
                    word.clear();
                }
            }
        }
        for(int i=words.size()-1; i>0; i--){
            // res.append(words[i]);
            res += words[i];
            res.append(" ");
        }
        res.append(words[0]);
        return res;
    }
};
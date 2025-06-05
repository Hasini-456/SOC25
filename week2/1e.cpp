// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int T;
//     cin>>T;
//     int l;
//     string ndl;
//     string hst;
    
//     while(T--){
//         cin>>l;
//         cin>>ndl;
//         cin>>hst;

//         //KMP table
//         vector<int> h(l+1, -1);
//         int i, j;
//         i=1; j=0;
//         while(i<l){
//             if(ndl[i] != ndl[j]){
//                 h[i] = j;
//                 while(j >= 0 && ndl[i] != ndl[j]){
//                     j = h[j];
//                 }//we are preparing this for i+1, so we need to go to a largest possible j such that ndl[0:j] = ndl[i-j:i]
                
//             }else{
//                 h[i] = h[j];
//             }
//             i++;
//             j++;
//         }
//         h[l] = j;

//         i = 0; j= 0;
//         vector<int> m;
//         //kmp for pattern matching
//         while(i<hst.length()){
//             if(hst[i] == ndl[j]){
//                 i++; j++;
//                 if(j == l){
//                     m.push_back(i-j);
//                     j = h[j];
//                 }
//             }else{
//                 j = h[j];
//                 if(j < 0){ //h[j] = -1 means  before j, i.e. until j-1 there is no suffix which is also a prefix, so not po
//                     i++; j++;
//                 }
//             }
//         }
//         sort(m.begin(), m.end());
//         if(m.empty()){
//             cout<<endl;
//         }
//         for(i=0; i<m.size(); i++){
//             cout<<m[i]<<endl;
//         }
//         cout<<endl;

//     }
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        // Read needle length
        int l = stoi(line);

        // Read needle
        string ndl;
        getline(cin, ndl);

        // Read haystack line-by-line, character by character
        // (We assume here haystack is just one line, but potentially large)

        string haystack_line;
        getline(cin, haystack_line);

        // Now stream character by character from haystack_line
        int i = 0, j = 0;
        vector<int> h(l + 1, -1);

        // Build KMP prefix table
        int x = 1, y = 0;
        while (x < l) {
            if (ndl[x] != ndl[y]) {
                h[x] = y;
                while (y >= 0 && ndl[x] != ndl[y]) {
                    y = h[y];
                }
            } else {
                h[x] = h[y];
            }
            x++; y++;
        }
        h[l] = y;

        // KMP search in streaming manner
        vector<int> matches;
        for (int idx = 0; idx < haystack_line.size(); idx++) {
            char c = haystack_line[idx];
            while (j >= 0 && c != ndl[j]) {
                j = h[j];
            }
            j++;
            if (j == l) {
                matches.push_back(idx - l + 1);
                j = h[j];
            }
        }

        for (int pos : matches) {
            cout << pos << "\n";
        }
        cout << "\n"; // blank line after each test case
    }
}

#include<bits/stdc++.h>
using namespace std;

// int main(){
//     string s;
//     cin>>s;
//     int n = s.length();
    
//     vector<int> v;
//     // for(int i=0; i<n-1; i++){
//     //     if(s[i] == s[n-1]){
//     //         v.push_back(i);
//     //     }
//     // }
//     int y=0;
//     while(true){
//         int k = s.find(s[n-1], y);
//         if(k == n-1) break;
//         else{
//             v.push_back(k);
//             y = k+1;
//         }
//     }
//     int possible = 0;
//     int index, l;
//     string t;
//     while(!v.empty()){
//         index = v.back(); //0 to index, i.e. length = index+1
//         v.pop_back();
//         l = index+1;
//         t =s.substr(0,l);
//         if(t == s.substr(n-l,l)){
//             int x = s.find(t, 1);
//             if(x!= n-l){
//                 //found 
//                 possible = 1;
//                 break;
//             }
//         }
//     }
//     if(possible == 1) cout<<t<<endl;
//     else cout<<"Just a legend"<<endl;
// }

int main(){
    string s;
    cin>>s;
    int n = s.length();
    vector<int> pi(n, 0); //v stores length of longest proper prefix of s[0..i] which is also a suffix
    unordered_map<int, int> freq;
    // for(int i=1; i<n; i++){
    //     if(s[i] == s[pi[i-1]]){
    //         pi[i] = pi[i-1]+1;
    //     }else{
    //         if(s[i] == s[0]) pi[i]=1;
    //         else pi[i] = 0;
    //     }
    //     freq[pi[i]] += 1;

    // }
    int j;
    //the below is very similar to calculating array h in kmp
    for(int i=1; i<n; i++){
        j = pi[i-1];
        while(j >0 && s[i] != s[j]){
            j = pi[j-1];
        }
        if(s[i] == s[j]){
            j++;
        }
        pi[i] = j;
        freq[pi[i]]++;
    }

    int found =0;

    int l;
    l = pi[n-1];
    freq[l]--;
    while(l > 0){
        if(freq[l] > 0) {
            found =1;
            break;
        }else{
            l = pi[l-1];
        }
    }

    if(found == 0) cout<<"Just a legend"<<endl;
    else{
        cout<<s.substr(0,l)<<endl;
    }
}
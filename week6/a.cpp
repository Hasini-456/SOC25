#include <iostream>
#include <vector>

using namespace std;

int dfs(int u, const vector<int>& manager, vector<int>& depth){
    if(depth[u] != -1) return depth[u];
    if(manager[u] == -1) return depth[u] = 1;
    return depth[u] = 1+dfs(manager[u], manager, depth);
}

int main(){
    int n;
    cin>>n;
    vector<int> manager(n);
    for(int i=0; i<n; i++){
        int p;
        cin>>p;
        manager[i] = (p == -1)? -1 : p-1;
    }

    vector<int> depth(n, -1); //depth of each employee
    int max_depth = 0;
    for(int i=0; i<n; i++){
        max_depth = max(max_depth, dfs(i, manager, depth));
    }

    cout<<max_depth<<endl;
}
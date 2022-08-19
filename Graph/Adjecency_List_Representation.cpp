#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    vector<int> arr[n + 1];
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        // Undirected Graph
        arr[u].push_back(v);
        arr[v].push_back(u);
        // For Directed Graph Comment out line number 11 ( u ---> v so edge here will only be present b/w u to v)
    }
    return 0;
}
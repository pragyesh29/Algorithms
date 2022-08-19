#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    vector<pair<int, int>> arr[n + 1];
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        arr[u].push_back(pair<int, int> {v, w});
        arr[v].push_back(pair<int, int> {u, w});
    }
    return 0;
}
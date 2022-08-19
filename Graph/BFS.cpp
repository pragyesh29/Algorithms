// i/p
// o/p : 1 2 6 3 4 7 9 5 8
#include<bits/stdc++.h>
using namespace std;

// Definition of each Node
struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode* right): val(x), left(left), right(right) {}
};

// BFS
vector<int> BFS(vector<int> adj[], int n){
    vector<int> res;
    queue<int> q;
    vector<int> vis(n, 0);
    q.push(1);
    vis[1] = 1;
    while(!q.empty()){
        int node = q.front();
        for(auto i : adj[node]){
            if(!vis[i]){
                vis[i] = 1;
                q.push(i);
            }
        }
        res.push_back(node);
        q.pop();
    }
    return res;
}

int main(){
    int n, m; cin >> n >> m;
    vector<int> arr[n + 1];
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    vector<int> res = BFS(arr, n);
    for(int i : res) cout << i << " ";
    return 0;
}

// Variable Description
// n -> Number of nodes
// m -> Number of edges
// arr -> Adjecency List
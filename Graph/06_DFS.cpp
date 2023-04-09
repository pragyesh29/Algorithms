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

void DFS(vector<int> arr[], vector<int> &viz, int start){
    cout << start << " ";
    for(auto it : arr[start]){
        if(!viz[it]){
            viz[it] = 1;
            DFS(arr, viz, it);
        }
    }
}

// DFS starting from node having value 1
void doDFS(vector<int> arr[], int n){
    vector<int> vis(n + 1,0);
    int startNode;
    cout << "Enter the starting node : ";
    cin >> startNode;
    vis[startNode] = 1;
    DFS(arr, vis, startNode);
}

int main(){
    int n, m; cin >> n >> m;
    vector<int> arr[n + 1];
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    doDFS(arr, n);
}

// Variable Description
// n -> Number of nodes
// m -> Number of edges
// arr -> Adjecency List
#include<bits/stdc++.h>
using namespace std;

// using DFS to find number of connected components
void dfs(int node, vector<int> adj[], int n, vector<bool> &viz){
    viz[node] = true;
    for(int i : adj[node]){
        if(!viz[i]) dfs(i, adj, n, viz);
    }
}

// using BFS to find number of connected components in graph
int numberOfConnectedComponentsDFS(vector<int> adj[], int n, vector<bool> viz){
    int res = 0;
    for(int i = 1; i <= n; i++){
        if(!viz[i]){
            res++;
            dfs(i, adj, n, viz);
        }
    }
    return res;
}

// using BFS to find number of connected components in graph
int numberOfConnectedComponentsBFS(vector<int> adj[], int n, vector<bool> viz){
    queue<int> q;
    // variable to keep count of number of connected components
    int res = 0;
    // mark node with value 0 by default as vizited as numbering of nodes is starting from 1
    viz[0] = true;
    for(int i = 1; i <= n; i++){
        // If node with value i is not vizited then this means it is a untraversed component
        if(!viz[i]){
            res++;
            q.push(i);
            viz[i] = true;
            while(!q.empty()){
                int x = q.front();
                q.pop();
                for(int i: adj[x]){
                    if(!viz[i]){
                        q.push(i);
                        viz[i] = true;
                    }
                }
            }
        }
    }
    return res;
}

int main(){
    int n, m;
    cout << "Enter number of nodes : ";
    cin >> n;
    cout << "Enter number of edges : ";
    cin >> m;
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool> viz(n+1, false);
    viz[0] = true;
    cout << numberOfConnectedComponentsBFS(adj, n, viz) << '\n';
    cout << numberOfConnectedComponentsDFS(adj, n, viz) << '\n';
    return 0;
}
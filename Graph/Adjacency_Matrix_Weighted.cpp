#include<iostream>
using namespace std;
int main(){
    int nodes, edges; cin >> nodes >> edges;
    int arr[nodes + 1][nodes + 1] = {0};
    for(int i = 0; i < edges; i++){
        int u, v, w; cin >> u >> v >> w;
        // u v -> nodes between which this edge is present
        // w -> weight of this edge
        arr[u][v] = arr[v][u] = w;
    }
    return 0;
}
#include<iostream>
using namespace std;
int main(){
    int nodes, edges; cin >> nodes >> edges;
    int arr[nodes + 1][nodes + 1] = {0};
    for(int i = 0; i < edges; i++){
        int u, v; cin >> u >> v;
        arr[u][v] = arr[v][u] = 1;
    }
    return 0;
}
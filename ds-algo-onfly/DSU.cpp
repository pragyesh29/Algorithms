#include <bits/stdc++.h>
using namespace std;

// DSU with union by size
class DSU{
    vector<int> parent;
    public:
    DSU(int n){parent.resize(n+1, -1);}

    int find(int node){
        if(parent[node] < 0) return node;
        
        return parent[node] = find(parent[node]);
    }

    bool isConn(int x, int y){
        return (find(x) == find(y));
    }

    void merge(int x, int y){
        int px = find(x), py = find(y);
        if(px != py){
            if(parent[px] <= parent[py]){
                parent[px] += parent[py];
                parent[py] = px;
            }else{
                parent[py] += parent[px];
                parent[px] = py;
            }
        }
    }

    void reset(int x){
        parent[x] = -1;
    }
};


// DSU with union by rank
class DSU{
    public:
    vector<int> parent, rank;
    DSU(int n){
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        rank.resize(n, 0);
    }
    
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void merge(int x, int y){
        int px = find(x), py = find(y);
        if(px != py){
            if(rank[px] == rank[py]){
                parent[py] = px;
                rank[px] += 1;
            }else if(rank[px] > rank[py]){
                parent[py] = px;
            }else{
                parent[px] = py;
            }
        }
    }

    bool isConn(int x, int y){
        return (find(x) == find(y));
    }

    void reset(int x){
        parent[x] = x;
        rank[x] = 0;
    }
};
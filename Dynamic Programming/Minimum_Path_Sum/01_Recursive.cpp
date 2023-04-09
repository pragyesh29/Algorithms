#include<bits/stdc++.h>
using namespace std;

int getMinPath(vector<vector<int>> &grid, int i, int j, int m, int n, int sum){
    // Out of Bounds
    if(i < 0 || i >= m || j < 0 || j >= n) return INT_MAX;
    // if we reach to the bottom right corner
    if(i == m-1 && j == n-1) return (sum + grid[i][j]);

    int x = getMinPath(grid, i+1, j, m, n, sum + grid[i][j]);
    int y = getMinPath(grid, i, j+1, m, n, sum + grid[i][j]);
    return min(x, y);
}

int main(){
    int m, n;
    cout << "Enter rows : ";
    cin >> m; 
    cout << "Enter columns : ";
    cin >> n;
    vector<vector<int>> grid;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    return 0;
}

// TESTING
// vector<vector<int>> grid{{1,3,1}, {1,5,1}, {4,2,1}};
// cout << getMinPath(grid, 0, 0, 3, 3, 0);
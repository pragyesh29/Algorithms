#include<bits/stdc++.h>
using namespace std;

int getMinPath(vector<vector<int>> &grid, int i, int j, int m, int n, int sum, vector<vector<int>> &dp){
    // Bounds
}

int main(){
    // int m, n;
    // cout << "Enter rows : ";
    // cin >> m; 
    // cout << "Enter columns : ";
    // cin >> n;
    // vector<vector<int>> grid;
    // for(int i = 0; i < m; i++){
    //     for(int j = 0; j < n; j++){
    //         cin >> grid[i][j];
    //     }
    // }
    vector<vector<int>> dp(3, vector<int> (3, INT_MAX));
    vector<vector<int>> grid{{1,3,1}, {1,5,1}, {4,2,1}};
    cout << getMinPath(grid, 0, 0, 3, 3, 0, dp);
    return 0;
}

// TESTING
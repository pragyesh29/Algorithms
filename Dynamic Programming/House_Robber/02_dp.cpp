#include<bits/stdc++.h>
using namespace std;

int getItems(int index, int sum, vector<int> &arr, int n, int dp[]){
    // base case for out of bound index
    if(index >= n){
        return sum;
    }

    // If solution for this subproblem is already solved then check in dp array and retur that
    if(dp[index] != -1) return dp[index];

    // Take item from this house and move ahead two steps, since now it will not be possible to take item from next consecutive house.
    int x = getItems(index + 2, sum + arr[index], arr, n, dp);
    // Don't take item form this house and move one step ahead
    int y = getItems(index + 1, sum, arr, n, dp);

    // return and store the solution of current problem state in dp array i.e since we have calculated not that what will be the maximum items robber can loot if he is at current index so simple return it and store it in dp array
    return dp[index] = max(x, y);
}

int main(){
    vector<int> arr{2, 7, 9, 3, 1};
    int dp[1001];
    memset(dp, -1, sizeof(dp));
    cout << getItems(0, 0, arr, arr.size(), dp);
    return 0;
}
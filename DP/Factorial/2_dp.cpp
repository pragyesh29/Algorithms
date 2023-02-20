#include<bits/stdc++.h>
using namespace std;

// Function to calculate factorial using dp array
int fact(int n, vector<int> &dp){
    if(dp[n] != -1) return dp[n];
    return dp[n] = n * fact(n - 1, dp);
}

int main(){
    int n; cin >> n;
    // Initializing dp container
    vector<int> dp(1001, -1);
    // factorial of 0 and 1 is 1
    dp[0] = dp[1] = 1;
    // Find factorial from 1 to n
    for(int i = 1; i <= n; i++){
        cout << fact(i, dp) << " ";
    }
    return 0;
}
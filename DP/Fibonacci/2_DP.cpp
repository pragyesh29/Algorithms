#include<bits/stdc++.h>
using namespace std;

int fibo(int n, vector<int> &dp){
    // If fibo(n) for this current n is calculated previously then use it from dp array in O(1) time.
    if(dp[n] != -1) return dp[n];
    // If not calculated previously then calculate and store it.
    return dp[n] = fibo(n - 1, dp) + fibo(n - 2, dp);
}

int main(){
    // Input from user until which pattern is needed to be printed
    int n; cin >> n;
    // Creating a dp container
    vector<int> dp(1001, -1);
    // Initialize first two terms 0 and 1
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 0; i < n; i++){
        cout << fibo(i, dp) << " ";
    }
    return 0;
}
// #DP approach
#include<bits/stdc++.h>
using namespace std;

// Given  s.length so create a dp array to store the resulting values.
int dp[102];

int decodeWays(string s, int index){
    int first = 0, second = 0;
    if(index >= s.size()){
        dp[index] = 1;
        return dp[index];
    }
    // Select only 1 char, which will be always valid unless it is 0
    if(s[index] != '0'){
        if(dp[index + 1]) first = decodeWays(s, index + 1);
         first = decodeWays(s, index + 1);
    }
    // Select 2 characters, and check if it is valid code for any alphabet
    if(index + 1 < s.size()){
        int tmp = (s[index] - '0') * 10 + (s[index + 1] - '0');
        if(tmp >= 10 and tmp <= 26){
            if(index + 2 < s.size() and dp[index + 2]) second = dp[index + 2];
            else second = decodeWays(s, index + 2);
        }
    }
    dp[index] = first + second;
    return dp[index];
}

int main(){
    memset(dp, 0, sizeof dp);
    cout << "Enter number of testcases : ";
    int t; cin >> t;
    while(t--){
        cout << "Enter string : ";
        string s; cin >> s;
        cout << decodeWays(s, 0) << '\n';
    }
    return 0;
}

// Time Complexity - O(2^n)
// Space Complexity - O(2^n)
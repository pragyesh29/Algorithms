// Write a program to print all unique subsequences whose sum is equal to given value
// i/p :  s = "12132" value = 4
// o/p : 112
#include<bits/stdc++.h>
using namespace std;

void getSubsequences(int currIndex, int currSum, string currStr, string s, int sumToCheckFor, unordered_set<string> &res){
    // BASE CONDITION
    // If currSum becomes equal to required sum
    if(currIndex == s.size()){
        // If this particular subsequence's sum is equal to required sum than put this in result ds
        if(currSum == sumToCheckFor) {
            res.emplace(currStr);
        }
        return;
    }

    // ELSE RECURSE FOR THE POSSIBLE SOLUTION
    // Don't take
    getSubsequences(currIndex + 1, currSum, currStr, s, sumToCheckFor, res);
    // Take
    getSubsequences(currIndex + 1, currSum + (s[currIndex] - '0'), currStr + s[currIndex], s, sumToCheckFor, res);
}

int main(){
    string s;
    // unordered_set Data structure to store unique results
    unordered_set<string> res;
    int checkSum;
    cout << "Enter string : ";
    cin >> s;
    cout << "Enter sum to check for : ";
    cin >> checkSum;
    getSubsequences(0, 0, "", s, checkSum, res);
    // Print the result
    for(string s: res){
        cout << s << " ";
    }
    return 0;
}
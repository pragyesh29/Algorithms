// Write a programt to print count of subsequences whose sum is equal to given value
// Write a program to print all unique subsequences whose sum is equal to given value
// i/p :  s = "12132" value = 4
// o/p : 112
#include<bits/stdc++.h>
using namespace std;

int getSubsequences(int currIndex, int currSum, string s, int sumToCheckFor){
    // BASE CONDITION
    // If currSum becomes equal to required sum
    if(currIndex == s.size()){
        // If this particular subsequence's sum is equal to required sum than return 1
        if(currSum == sumToCheckFor) {
            return 1;
        }
        return 0;
    }

    // RECURSE FOR THE POSSIBLE SOLUTION
    // Case : Don't take
    int l = getSubsequences(currIndex + 1, currSum, s, sumToCheckFor);
    // Case : Take
    int r = getSubsequences(currIndex + 1, currSum + (s[currIndex] - '0'), s, sumToCheckFor);

    return l + r;
}

int main(){
    string s;
    int checkSum;
    cout << "Enter string : ";
    cin >> s;
    cout << "Enter sum to check for : ";
    cin >> checkSum;
    cout << getSubsequences(0, 0, s, checkSum);
    return 0;
}
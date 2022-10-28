// #Recursive approach
#include<bits/stdc++.h>
using namespace std;
int decodeWays(string s, int index){
    int first = 0, second = 0;
    if(index >= s.size()){
        return 1;
    }
    // Select only 1 char, which will be always valid unless it is 0
    if(s[index] != '0'){
         first = decodeWays(s, index + 1);
    }
    // Select 2 characters, and check if it is valid
    if(index + 1 < s.size()){
        int tmp = (s[index] - '0') * 10 + (s[index + 1] - '0');
        if(tmp >= 10 and tmp <= 26){
            second = decodeWays(s, index + 2);
        }
    }
    return first + second;
}

int main(){
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
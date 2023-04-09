// For the given integer n generate all possible valid homogeneous set of parenthesis.
#include<bits/stdc++.h>
using namespace std;

void generateParenthesis(int open, int close, string ds, vector<string> &res, int n){
    // if both open and close are n numbers then this means we found a valid set of brackets.
    if(open == n && close == n){
        res.push_back(ds);
        return;
    }

    // If number of open brackets are less than number of close ones then this will certainly a invalid set
    if(open < close) return;

    // we will open the bracket only if number of brackets opened till now is less than n
    if(open < n){
        ds += '(';
        generateParenthesis(open + 1, close, ds, res, n);
        ds.pop_back();
    }

    // we will close the bracket only if number of brackets closed till now is less than n
    if(close < n){
        ds += ')';
        generateParenthesis(open, close + 1, ds, res, n);
        ds.pop_back();
    }
}

int main(){
    int n;
    cout << "Enter n : ";
    cin >> n;

    // container to store valid set of parenthesis
    vector<string> res;
    generateParenthesis(0, 0, "", res, n);


    // display the result
    for(int i = 0; i < res.size()-1; i++){
        cout << res[i] << " , ";
    }
    cout << res[res.size()-1];
    return 0;
}
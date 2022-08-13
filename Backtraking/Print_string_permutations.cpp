#include <bits/stdc++.h>
using namespace std;

// Method to print all possible permutations of the given String.
// This method does not check for the duplicate elements.
// This metho uses backtracking to achieve the desired result.
void permute(string s, int l, int r){
    if(l == r) cout << s << '\n';
    else{
        for(int i = l; i <= r; i++){
            swap(s[l], s[i]);
            permute(s, l+1, r);
            // backtrack
            swap(s[l], s[i]);
        }
    }
}

int main(){
    string s; cin >> s;
    permute(s, 0, s.size()-1);
    return 0;
}
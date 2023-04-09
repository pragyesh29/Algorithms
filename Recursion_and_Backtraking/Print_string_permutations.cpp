#include <bits/stdc++.h>
using namespace std;

// Method to print all possible permutations of the given String.
// This method does not check for the duplicate elements.
// This method uses backtracking to achieve the desired result.
void permutation(string original, int currIndex, int size, unordered_set<string> &ds){
    // BASE CASE
    if(currIndex == size){
        ds.emplace(original);
        return;
    }else{
        for(int i = 0; i < size; i++){
            swap(original[i], original[currIndex]);
            permutation(original, currIndex + 1, size, ds);
            swap(original[i], original[currIndex]);
        }
    }
}

// DRIVER
int main(){
    string s;
    cout << "Enter string to permute : ";
    cin >> s;
    // Data structure to store the result
    // Using unordered_set to print unique permutations
    unordered_set<string> ds;

    permute(s, 0, s.size());

    // Print all the resultant permutations of the string
    for(string i: ds) cout << i << " ";
    return 0;
}
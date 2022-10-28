// #Recursive approach
#include<bits/stdc++.h>
using namespace std;

int diceRolls(int curr, int n, int k, int target, int index){
    int x = 0;
    // Base case
    // If current sum is equal to target and we also reached to end
    if(curr == target and index == n) return 1;
    // If current sum is not equal to target and we reached to end
    if(index == n) return 0;

    for(int i = 1; i <= k; i++){
        x += diceRolls(curr + i, n, k, target, index + 1);
    }
    return x;
}

int main(){
    cout << "Enter number of testcases : ";
    int t; cin >> t;
    while(t--){
        int n, k, target;
        cout << "Enter number of dice, number of faces of each die and target value : ";
        cin >> n >> k >> target;
        cout << diceRolls(0, n, k, target, 0) << '\n';
    }
    return 0;
}

// Time Complexity - O(2^n)
// Space Complexity - O(2^n)
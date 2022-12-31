#include<iostream>
using namespace std;

// Function to find number of unique paths through combinatorics
// Simply permute(arrange) the number of right(R) or down(D) moves
int getPaths(int row, int col){
    // Total steps needed to be taken
    int n = row + col - 2;
    // To store result
    double res = 1;
    // To get minimum value in the binomial coefficient's subscript
    // nCr = nC(n-r)
    int dr = min(row - 1, col - 1);
    // Calculating value of binomial coefficient
    for(int i = n, j = dr; j > 0; i--, j--){
        // Explicit casting to use double version of operator / else int will be returned as result
        res = res * (i / (double)j);
    }
    // IMPORTANT STEP
    // There will be cases when res will have values like 19.9 etc. so following will take care of those such cases.
    return (int)(res + 0.1);
}

int main(){
    int row, col;
    cin >> row >> col;
    cout << getPaths(row, col);
    return 0;
}
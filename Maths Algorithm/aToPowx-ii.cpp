#include<iostream>
#include<vector>
using namespace std;

void getXn(int x, int n, vector<int> &res){
    for(int i = 0; i < n; i++){
        int carry = 0, l = res.size();
        // Storing result in reverse order for ease
        for(int j = 0; j < l; j++){
            // Multiply each digit of result with base i.e. x and adding carry if present.
            int tmp = res[j] * x + carry;
            // If the calculated value is greater than 9 then we write least significant value (last digit) in the cell
            res[j] = tmp % 10;
            // If the calculated value is greater than 9 then we write last digit in the cell and remaining will be treated as carry.
            carry = tmp / 10;
        }
        // At last check if carry is remaining, if yes then push the carry in the end of the resultant array.
        // If no carry present then keep traversing in the loop n times (at max)
        if(carry){
            res.push_back(carry);
        }
    }
}

void printArrRev(vector<int> &res){
    for(auto i = res.rbegin(); i != res.rend(); i++){
        cout << *i;
    }
}

int main(){
    int x, n;
    cout << "Enter x : ";
    cin >> x;
    cout << "Enter n : ";
    cin >> n;
    // Initialize the array with base of exponent.
    vector<int> res{x};
    // n - 1 because, we already initialized our array with base.
    getXn(x, n - 1, res);
    // Helper Function to print the contents in reverse order
    printArrRev(res);
    // for(int i = res.size() - 1; i >= 0; i--) cout << res[i];
    return 0;
}
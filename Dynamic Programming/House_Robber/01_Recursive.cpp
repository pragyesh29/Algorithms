// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
// i/p : nums = [2,7,9,3,1]
// o/p : 12
#include<bits/stdc++.h>
using namespace std;

int getItems(int index, int sum, vector<int> &arr, int n){
    // base case for out of bound index
    if(index >= n){
        return sum;
    }
    // Take item from this house and move ahead two steps, since now it will not be possible to take item from next consecutive house.
    int x = getItems(index + 2, sum + arr[index], arr, n);
    // Don't take item form this house and move one step ahead
    int y = getItems(index + 1, sum, arr, n);
    return max(x, y);
}

int main(){
    vector<int> arr{2, 7, 9, 3, 1};
    cout << getItems(0, 0, arr, arr.size());
    return 0;
}
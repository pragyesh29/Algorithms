// Write a program to return sum of all possible subsequences in sorted order
// Ex. [5,2,1]
// o/p -> [0, 1, 2, 3, 5, 6, 7, 8] 
// As possible subsets will be [{0}, {0, 1}, {2}, {3}, {5}, {1,5}, {2,5}, {1,2,5}]
#include<bits/stdc++.h>
using namespace std;
// Function to evaluate the sum of all possible combinations in sorted order
void getCombinations(vector<int> &arr, vector<int> &res, int index, int currsum, int n){
    // BASE CASE
    if(index == n){
        res.push_back(currsum);
        return;
    }
    // Don't take current Index's value
    getCombinations(arr, res, index + 1, currsum, n);
    // Take current index's value
    getCombinations(arr, res, index + 1, currsum + arr[index], n);
}

int main(){
    // Input
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> res;

    // To obtain result in sorted order we will sort the input in descending order.
    // We could also sort the resultant vector containing the sum of all the subset but that will be not good if n will be large. Because then (2^n) number of subsets will be generated.
    // Example if n = 100 then the size of the resulant array containing sum will be (2^100) which is very large set of data to sort compared to array containg only 100 elements.
    sort(arr.begin(), arr.end(), greater<int>());

    // calling function to evaluate combination sum
    getCombinations(arr, res, 0, 0, n);

    // printing the result
    for(int i: res){
        cout << i << " ";
    }
    return 0;
}
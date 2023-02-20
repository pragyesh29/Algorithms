// Write algo to print next lexicographical permutation of number n
// Example i/p - 14243643
// o/p - 14244336


// Check for error
#include <bits/stdc++.h>
using namespace std;
bool next_permutation(vector<int> &arr){
    int n = arr.size();
    int j = n - 1;
    while(j > 0 && arr[j] <= arr[j - 1]) j--;
    if(j <= 0){
        cout << "given input is already the largest permutation\n";
        return false;
    }
    int pivot = j - 1;
    j = n - 1;
    while(j > pivot && arr[j] <= arr[pivot]) j--;
    swap(arr[j], arr[pivot]);
    reverse(arr.begin() + pivot, arr.end());
    return true;
}

int main(){
    vector<int> arr{1,2,3};
    while(next_permutation(arr)){
        for(int i: arr) cout << i << " ";
        cout << '\n';
    }
    return 0;
}
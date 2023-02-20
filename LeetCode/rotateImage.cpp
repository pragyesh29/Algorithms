#include<bits/stdc++.h>
using namespace std;

// Print the matrix
void printArr(vector<vector<int>> &arr){
    for(auto i : arr){
        for(int j : i){
            cout << j << " ";
        }
        cout << '\n';
    }
}

// For transpose res[i][j] = arr[j][i] in O(1) space
void transpose(vector<vector<int>> &arr){
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j <= i; j++){
            swap(arr[i][j], arr[j][i]);
        }
    }
}

// Function to rotate array in clockwise direction
void clockwiseRotation(vector<vector<int>> arr){
    int n = arr.size();
    transpose(arr);
    for(int i = 0; i < n; i++){
        reverse(arr[i].begin(), arr[i].end());
    }
    printArr(arr);
}

// Function to rotate array in anticlockwise direction
void anticlockwiseRotation(vector<vector<int>> arr){
    int n = arr.size();
    transpose(arr);
    // simply reverse the arrays inside the array.
    reverse(arr.begin(), arr.end());
    printArr(arr);
}

int main(){
    vector<vector<int>> arr{{1,2,3,4}, {4,5,6,7}, {7,8,9,10}, {11,2,13,1}};
    cout << "Original array : \n";
    printArr(arr);
    cout << "\nClockwise Rotated array is : \n";
    clockwiseRotation(arr);
    cout << "\nAnticlockwise Rotated array is : \n";
    anticlockwiseRotation(arr);
    return 0;
}
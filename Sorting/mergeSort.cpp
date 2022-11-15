#include <iostream>
#include<vector>
using namespace std;

// Merge function to merge two unsorted string in sorted order
void merge(vector<int> &arr, int start, int mid, int end){
    // Length of first Chunk (Sub array)
    int firstArr = mid - start + 1;
    // Length of second Chunk (Sub array)
    int secondArr = end - mid;

    // Creating and copying the data into the arrays.
    vector<int> left(firstArr, 0);
    for(int i = 0; i < firstArr; i++){
        left[i] = arr[i + start];
    }
    vector<int> right(secondArr, 0);
    for(int i = 0; i < secondArr; i++){
        right[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, c = start;
    while(i < firstArr and j < secondArr){
        if(left[i] <= right[j]){
            arr[c++] = left[i++];
        }else{
            arr[c++] = right[j++];
        }
    }

    while(i < firstArr){
        arr[c++] = left[i++];
    }

    while(j < secondArr){
        arr[c++] = right[j++];
    }
}

// Recursive mergeSort Function to seperate the original array into chunks then merge in sorted order using merge() function
void mergeSort(vector<int> &arr, int start , int end){
    if(start >= end) return;
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

// Function to print the contents of the Array
void printArr(vector<int> &arr){
    for(int i : arr){
        cout << i << " ";
    }
}

// Driver Function
int main(){
    // Original unsorted array
    vector<int> arr{10, 8, 34, 2, 4, 25, 14, 22, 12, 89};
    int size = arr.size();
    mergeSort(arr, 0, size - 1);
    printArr(arr);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

// helper function to print elements in the array.
void printAll(int *arr, int N){
    for(int i=0; i<N; i++){cout<<arr[i]<<" ";}
    cout<<endl;
}

// funciton to perform count sort algorithm
void countSort(int *arr, int N, int R){

    // Frequency array for the storing frequency of each element
    int freq[R]={0};
    // Resulting array to store resulting sorted array
    int res[N];
    // Storing the frequency of each element from arr into freq array
    for(int i=0; i<N; i++){ freq[arr[i]]++; }
    // Performing addition on every element in array to add current and previous element
    for(int i=1; i<R; i++){ freq[i]+=freq[i-1]; }
    
    // Main logic
    for(int i=0; i<N; i++){
        // getting arr[i] as a index for freq array
        int idx = freq[arr[i]];
        // first decrement value because of because we will use this as index for resulting arr, and as we know indexing is zero based.
        idx--;
        // store the arr[i] element at this index in our resulant aray
        res[idx] = arr[i];
    }
    
    // Copy the resultant sorted array to arr
    for(int i=0; i<N; i++){arr[i] = res[i];}
}
int main(){
    int arr[] = {6,5,4,3,2,1};
    int N = sizeof(arr)/sizeof(arr[0]);
    // Defining Max Range of elements in arr. 
    int R = 10;
    printAll(arr,N);
    countSort(arr, N, R);
    printAll(arr,N);
}
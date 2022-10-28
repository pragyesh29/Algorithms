#include<iostream>
#include<cstdlib>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        int j = i + 1;
        while(arr[j] < arr[j - 1] and j > 0){
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }

    cout << "\nSorted array   : ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
}

int main(){
    int n;
    cout << "Enter number of elements : ";
    cin >> n;
    int arr[n];
    cout << "Original array : ";

    // filling random numbers upto two digits inside array
    for(int i = 0; i < n; i++){
        arr[i] = rand() % 100 + 1;
        cout << arr[i] << " ";
    }

    insertionSort(arr, n);

    return 0;
}
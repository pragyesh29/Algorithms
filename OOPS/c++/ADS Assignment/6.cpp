#include<iostream>
using namespace std;

// function to take input of non null elements of lower triangular matrix
// no of non-null elements in lower triangular matrix of order N is = N(N+1)/2
// no of null elements in lower triangular matrix of order N is = N(N-1)/2
void input(int **arr, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i+1; j++){
            cin >> arr[i][j];
        }
    }
}

// function to print the lower triangular matrix
void printArr(int **arr, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j < i+1) cout << arr[i][j] << " ";
            else cout << 0 << " ";
        }
        cout << '\n';
    }
}

int main(){
    int **arr;
    int n;
    cout << "Enter n : ";
    cin >> n;
    arr = new int*[n];
    for(int i = 0; i < n; i++){
        arr[i] = new int[i+1];
    }
    cout << "Enter non-null elements of arr matrix : \n";
    input(arr, n);
    cout << "Elements of lower triangular matrix is : \n";
    printArr(arr, n);
    return 0;
}
// Write a program to multiply 
#include<iostream>
using namespace std;
void input(int **arr, int n){
    for(int i = 0; i < n; i++){
        arr[i] = new int[i+1];
        for(int j = 0; j < i+1; j++){
            cin >> arr[i][j];
        }
    }
    cout << '\n';
}

void printMatrix(int **arr, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << ((j < i+1) ? arr[i][j] : 0);
            cout << " ";
        }
        cout << '\n';
    }
}

int** mutipilcation_Of_LTM_With_LTM(int **first, int **second, int n){
    int **res = new int*[n];
    for(int i = 0; i < n; i++){
        res[i] = new int[n];
        for(int j = 0; j < n; j++){
            res[i][j] = 0;
            // if(j < i+1){
            //     for(int k = 0; k < n; k++){
            //         res[i][j] += (first[i][k] * second[k][j]);
            //     }
            // }
        }
    }
    return res;
}

using namespace std;
int main(){
    int **first, **second;
    cout << "Enter order of matrix : ";
    int n; cin >> n;
    first = new int*[n];
    second = new int*[n];
    cout << "Enter elements in first matrix : \n";
    input(first, n);
    cout << "First Matrix is : \n";
    printMatrix(first, n);
    cout << "Enter elements in second matrix : \n";
    input(second, n);
    cout << "Second Matrix is : \n";
    printMatrix(second, n);
    cout << "Multiplication of both matrix is : \n";
    int **res = mutipilcation_Of_LTM_With_LTM(first, second, n);
    printMatrix(res, n);
    return 0;
}
#include<iostream>
using namespace std;

const int n = 3;

void multiply(int first[][n], int second[][n]){
    int res[n][n] = {0};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                res[i][j] += first[i][k] * second[k][j];
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    // cout << "Enter dimentions of both matrix";
    // int n; cin >> n;
    int first[n][n] = {{1,2,3},{4,5,6},{7,8,9}};
    int second[n][n] = {{9,8,7},{6,5,4},{3,2,1}};
    multiply(first, second);
    return 0;
}
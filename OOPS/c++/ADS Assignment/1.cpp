#include<iostream>
using namespace std;
class Array{
    int n;
    int *arr;
    public:
    Array(int n){
        this->n = n;
        arr = new int[n];
    }
    void insert(int index, int data){
        arr[index] = data;
    }
    friend void printArr(Array &a, int n);
    friend void store(Array &a, int n);
};

void store(Array &a, int n){
    int odd = 1, even = n;
    int left = 0, right = n-1;
    while(left < right){
        a.insert(left, odd);
        a.insert(right, even);
        odd += 2;
        even -= 2;
        left++; right--;
    }
}

void printArr(Array &a, int n){
    for(int i = 0; i < n; i++){
        cout << a.arr[i] << " ";
    }
    cout << '\n';
}

int main(){
    int n;
    while(cout << "Enter n : " && cin >> n){
        if(n&1){
            cout << "Invalid input...\nvalue of n must be even\n";
            continue;
        }else{
            break;
        }
    }
    Array arr(n);
    store(arr, n);
    printArr(arr, n);
    return 0;
}
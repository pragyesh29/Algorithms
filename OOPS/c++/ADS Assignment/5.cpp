#include<iostream>
#include<cassert>
using namespace std;
class Array{
    int n;
    public:
    int *arr;
    Array(int n){
        this->n = n;
        arr = new int[n];
    }
    void insert(int, int);
    void display();
    void getsize();
    void deleteElement(int);
};

void Array::getsize(){
    cout << n << endl;
}

void Array::display(){
    for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
    }
    cout << endl;
}

void Array::insert(int data, int index){
    assert(index >= 0 && index < n);
    arr[index] = data;
}

void Array::deleteElement(int index){
    assert(index >= 0 && index < n);
    for(int i = index; i < n-1; i++){
        arr[i] = arr[i+1];
    }
    n--;
    cout << "Array after deletion of element at index " << index << " is : ";
    display();
}

void store(Array &a, int n){
    
    for(int i = 0; i < n; i++){
        cout << a.arr[i] << " ";
    }
    cout << '\n';
}

void deleteDuplicatesInMinimumMovements(Array &a, int n){
    for(int i = 2; i < n; i+=2){
        for(int j = i; j < n - 1; j++){
            a.arr[j] = a.arr[j+1];
        }
        n--;
    }
    for(int i = 0; i < n; i++){
        cout << a.arr[i] << " ";
    }
}

void deleteDuplicatesMaximumMovements(Array &a, int n){
    // Implement
}

int main(){
    cout << "Enter n : ";
    int n; cin >> n;
    assert(!(n&1));
    Array arr(n);
    store(arr, n);
    deleteDuplicatesInMinimumMovements(arr, n);
    return 0;
}
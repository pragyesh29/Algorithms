#include<bits/stdc++.h>
using namespace std;

// Iterative program to print fibonacci sequence upto given input
void fibo(int n){
    int a = 0, b = 1;
    if(n == 1){
        cout << n;
        return;
    }
    // Print first two terms
    cout << a << " " << b << " ";
    // Decrement count by two as we already printed first two terms i.e. 0 and 1.
    n -= 2;

    while(n--){
        int sum = a + b;
        a = b;
        b = sum;
        cout << sum << " ";
    }
}

int main(){
    // Input of number of terms user wants to print
    int n; cin >> n;
    fibo(n);
    return 0;
}
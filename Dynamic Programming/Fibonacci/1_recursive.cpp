#include<bits/stdc++.h>
using namespace std;

int fibo(int n){
    // Base case
    if(n <= 1) return n;
    return fibo(n - 1) + fibo(n - 2);
}

int main(){
    // Number of terms upto which pattern is to be printed
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cout << fibo(i) << " ";
    }
    return 0;
}
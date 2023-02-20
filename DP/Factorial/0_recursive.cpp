#include<bits/stdc++.h>
using namespace std;

// Function to calculate factorial using dp array
long long fact(long long n){
    if(n <= 2) return n;
    return n * fact(n - 1);
}

int main(){
    long long n; cin >> n;
    // Find factorial from 1 to n
    for(int i = 1; i <= n; i++){
        cout << fact(i) << " ";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

// function to check if number is prime or not
bool isPrime(int n){
    int c = 0;
    if(n % 2 == 0) c++;
    while(n % 2 == 0) n /= 2;
    for(int i = 3; i < sqrt(n); i++){
        if(n % i == 0){
            c++;
            n /= 2;
            i--;
        }
    }
    if(c > 0) return false;
    return true;
}

// Driver function
int main(){
    int n; cin >> n;
    vector<int> arr(n + 1, true);
    arr[0] = arr[1] = false;
    for(int i = 2; i < sqrt(n); i++){
        if(arr[i])
            for(int j = i * i; j <= n; j += i) arr[j] = false;
    }
    for(int i = 0; i <= n; i++){
        if(arr[i]) cout << i << " ";
    }
    return 0;
}
// Trial Division algo to check if number is prime or not
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout << "Enter the number : ";
    cin >> n;
    // If number is composite then it must have at least 1 divisor d, such that d <= sqrt(n) => d * d <= n
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            cout << "Not a prime number\n";
            return 0;
        }
    }
    cout << "Number is prime!!\n";
}
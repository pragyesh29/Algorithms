#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter number : ";
    cin >> n;
    int beg = 0, end = n, mid, precision;
    double ans = 0.0, increment = 0.1;
    cout << "Enter number of decimal places upto which answer should be given : ";
    cin >> precision;
    // Binary Search to get integral part of the root of given number
    while(beg <= end){
        mid = (beg + end) / 2;
        int sqr = mid * mid;
        if(sqr == n){
            cout << mid;
            return 0;
        } else if(sqr > n){
            end = mid - 1;
        } else{
            ans = mid;
            beg = mid + 1;
        }
    }
    // Getting demical part upto specified number of places
    while(precision--){
        while(ans * ans <= n){
            ans += increment;
        }
        ans -= increment;
        increment /= 10;
    }
    cout << ans;
    return 0;
}
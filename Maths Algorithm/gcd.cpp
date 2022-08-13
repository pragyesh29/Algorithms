#include<bits/stdc++.h>
using namespace std;

//recursive gcd funtion
int gcd(int first, int second){
    if(first == second) return first;
    if(first == 0) return second;
    if(second == 0) return first;
    if(first > second) return gcd(first % second, second);
    return gcd(first, second % first);
}

// helper function
int main(){
    int a,b; cin>>a>>b;
    cout << gcd(a, b);
    return 0;
}
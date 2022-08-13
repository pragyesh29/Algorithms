// i/p 3

// o/p [1,3,3,1]

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    //container to store resultant row of Pascal Triangle
    // 1st row contains 1 element
    // 2nd row contains 2 element
    // 3rd row contians 3 element
    // .
    // .
    // .
    // nth row contains n element
    vector<int> result(n+1, 1);
    long multiplicative_factor = 1;
    for(int i=0; i<=n; i++){
        result[i] = multiplicative_factor;
        multiplicative_factor = result[i] * (n-i)/(i+1);
    }

    for(int i: result) cout<<i<<" ";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,r; cin>>n>>r;

    // nCr = nC(r-1)
    r = min(r, n-r);
    double result = 1.0;

    // nCr = (n/r)n-1Cr-1 = (n/r)(n-1/r-1)n-2Cr-2
    // 5C3 = (5/3)4C2 = (5/3)(4/2)3C1 = (5/3)(4/2)(3/1)
    for(int i=r; i>=1; i--){
        result *= ((double)n/i);
        n--;
    }

    // Here we carefully cast the floating point number to an integer,
    // taking into account that due to the accumulated errors,
    // it may be slightly less than the true value (for example, 2.99999 instead of 3.0).
    cout << (int)(result+0.1);
}
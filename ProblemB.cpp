https://codeforces.com/contest/1758/problem/B
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n; cin >> n;
    if(n&1){
        // For n = Odd
        // x ⊕ x ⊕ x ⊕ x ⊕ x ⊕ ... x ⊕ x ⊕ ...n times = x
        // And mean of x, x, x, x, ... x, x, ... n times = x; since all observations have same value
        // Let x = 4
        for(int i = 0; i < n; i++){
            cout << 4 << " ";
        }
    }else{
        // For n = Even
        // Fact : 2 ⊕ 6 = 4
        // Let n = 8
        // [ 2 ⊕ 6 ] ⊕ 4 ⊕ 4 ⊕ 4 ⊕ 4 ⊕ 4 ⊕ 4 = 4
        // and mean = [(2 + 6) + 4 + 4 + 4 + 4 + 4 + 4] / 8 = 4
        // First print 2 and 6
        cout << 2 << " " << 6 << " ";
        // Decrease value of n by two since two values i.e. 2 and 6 are printed
        n -= 2;
        // Then print 4 for remaining n number of times
        for(int i = 0; i < n; i++) cout << 4 << " ";
    }
    cout << '\n';
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

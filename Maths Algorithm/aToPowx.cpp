#include<bits/stdc++.h>
using namespace std;

string toBinary(int n){
    string res = "";
    while(n){
        res += to_string(n % 2);
        n /= 2;
    }
    return res;
}

void solve(){
    int a, x;
    cin >> a >> x;
    string s = toBinary(x);
    long long res = 1, curr = a;
    for(int i = 0; i < s.length(); i++){
        if(i == 0)
            if(s[i] == '1') res = a;
            else res = 1;
        else{
            curr = curr * curr;
            if(s[i] == '1') res *= curr;
        }
    }
    cout << res;
}

int main(){
    // int T; cin>>T;
    // while(T--){
        solve();
    // }
}
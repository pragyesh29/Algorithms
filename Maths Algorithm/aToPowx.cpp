#include<bits/stdc++.h>
using namespace std;

//helper function to return string of binary form of given decimal number
string toBinary(int n){
    string res = "";
    while(n){
        res += to_string(n % 2);
        n /= 2;
    }
    return res;
}

int main(){
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
#include<bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)(x.size()))
#define FOR(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REP(i,a,b) for(int (i)=(a);(i)<(b);++i)
#define all(x) x.begin(),x.end()

typedef long long ll;

void solve(){
    vector<int> arr = {1, 5, -2, 6, 8, -7, 2, 1, 11, 10};
    int len = arr.size();
    int no_of_elements_per_block = sqrt(len);
    vector<int> sum_per_block(no_of_elements_per_block + 1, 0);
    for(int i=0; i<len; i++){
        sum_per_block[i/no_of_elements_per_block] += arr[i];
    }
    for(int i: sum_per_block) cout<<i<<" ";
    cout<<endl;

    // Handling query expected
    int sumquery = 0;
    int l = 1, r = 8;
    
    while(l<r && l%no_of_elements_per_block!=0){
        sumquery += arr[l];
        l++;
    }
    while(l+no_of_elements_per_block-1 <= r){
        sumquery += sum_per_block[l/no_of_elements_per_block];
        l += no_of_elements_per_block;
    }
    while(l <= r){
        sumquery += arr[l];
        l++;
    }

    cout<< sumquery <<endl;

    // Handling update
    int index = 2; int val = 4;
    sum_per_block[index / no_of_elements_per_block] = (sum_per_block[index / no_of_elements_per_block]) - arr[index] + val;
    arr[index] = val;

    for(int i: sum_per_block) cout<<i<<" ";
    cout<<endl;
}

int main(){
    solve();
}
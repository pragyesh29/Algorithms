#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<vector<int>> result;
    for(int i=0; i<n; i++){
        vector<int> v(i+1, 1);
        if(i > 1){
            for(int j=1; j<i; j++){
                v[j] = result[i-1][j-1] + result[i-1][j];
            }
        }
        result.push_back(v);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout<<result[i][j];
        }
        cout<<endl;
    }
}
#include<bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)(x.size()))
#define FOR(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REP(i,a,b) for(int (i)=(a);(i)<(b);++i)
#define w(T) int T;cin>>T;while(T--)
#define all(x) x.begin(),x.end()

typedef long long ll;

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
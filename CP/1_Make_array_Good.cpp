// https://codeforces.com/contest/1762/problem/B
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int m; cin >> m;
    // to count number to opeartions required to in order to get to the result
    int count = 0;
    // to store the result
    vector<pair<int, int>> res;
    // to keep track of the original index of the a[i], as we will sort the array further, we need to use addional data structure. Here  we are using an vector of pair
    vector<pair<long long, long long>> arr;
    // Takin input in array of size m
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        // pushing pair, <a[i], i> with value and its corresponding original index
        arr.push_back(pair<long long, long long> {x, i});
    }
    // Sorting the array
    sort(arr.begin(), arr.end());
    
    // concept now is to make every element a[i] as a nearest multiple of a[i - 1]
    // As the relation 'divides' follows trasitivity i.e.
    // If a divides b and b divides c then it is implied that a will also divide c.
    for(int i = 1; i < m; i++){
        int r;
        // if current element i.e. a[i] is not divisible by a[i - 1] then
        if(arr[i].first % arr[i - 1].first != 0){
            // if current element is smaller than its previous element then simply make current element same as previous element as any number always divides itself
            if(arr[i - 1].first > arr[i].first){
                r = arr[i - 1].first - arr[i].first;
            }else{
            // otherwise make the current element as a nearest multiple of its previous element
            // to make any number x as nearest multiple of y => (abs(x/y) + 1) * y
            // ex to make 14 as multiple of 4 => (abs(14/4) + 1) * 4 = 16
                r = ((arr[i].first / arr[i - 1].first + 1) * arr[i - 1].first) - arr[i].first;
            }
            // update the current element
            arr[i].first += r;
            // increment the count
            count++;
            // push the original index of the current element and x, where x <= a[i]
            res.push_back(pair<int, int> {(int)arr[i].second + 1, r});
        }
    }

    // Print the result
    cout << count << '\n';
    for(auto i : res){
        cout << i.first << " " << i.second << '\n';
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
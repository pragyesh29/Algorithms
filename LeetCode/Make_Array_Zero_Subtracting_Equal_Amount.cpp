#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int makeZero(vector<int> arr){
    // In first operation smallest (excluding 0) will make value to zero
    // In second operation next smallest (excluding 0) will make value zero
    // In third operation next smallest (excluding 0) will make value zero
    // .
    // .
    // .
    // This will keep on going till there will be a non zero poisitive number left in the array
    // So we just need to count number of UNIQUE POSITIVE elements

    unordered_set<int> uset;
    for(int i: arr){
        // If element is not zero
        if(i) uset.insert(i);
    }

    cout << uset.size() <<'\n';
}

int main(){
    vector<int> arr = {1, 5, 0, 3, 5};
    cout << makeZero(arr);
}
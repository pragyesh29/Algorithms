#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Segment{
    int n;
    vector<ll> seg;
    public:
    Segment(int x){
        n = x;
        seg.resize(4*n,0);
    }

    int query(int index, int low, int high, int l, int r){
        if(low >= l && high <= r){
            return seg[index];
        }
        if(r < low || l > high){
            return INT_MIN;
        }
        int mid = (low + high)/2;
        int x = query(2*index+1, low, mid, l, r);
        int y = query(2*index+2, mid+1, high, l, r);
        return max(x, y);
    }

    int fire(int l, int r){
        return query(0, 0, n-1, l, r);
    }

    void build(int index, vector<ll> &arr, int low, int high){
        if(low == high){
            seg[index] = arr[low];
            return;
        }
        ll mid = (low + high)/2;
        build(2*index+1, arr, low, mid);
        build(2*index+2, arr, mid + 1, high);

        // Change this for whatever operation needed by def it is addition
        seg[index] = seg[2*index+1] + seg[2*index+2];
    }
};
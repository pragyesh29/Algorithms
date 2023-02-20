#include<bits/stdc++.h>
using namespace std;

// Original array with data
int arr[] = {8, 10, 20, 1, 2, 5, 0, 9};
// Length of above array
const int n = sizeof(arr)/sizeof(arr[0]);
// Create a array which will represent segment tree and initialize every item to zero. The size of the segmenet tree is 4*n because for n items in array the segment tree can have at mose 4*n childrens.
int seg[n * 4] = {0};

// Function to perform query in O(log(n)) time
int query(int index, int low, int high, int l, int r){
    // If range of node represented by index in segment tree is -:

    // lying completely inside the given range i.e. if [low, high] ⊆ [l, r] then simply return the node's value.
    if(low >= l && high <= r){
        return seg[index];
    }
    // not lying in the given range at all i.e. if [low, high] ⊄ [l, r] then simply return the INT_MIN to get maximum value or return INT_MAX if minimum value is needed from query.
    if(r < low || l > high){
        return INT_MIN;
    }
    // partially overlapping in the given range then traverse to both left and right childs
    int mid = (low + high)/2;
    // Traverse to left child
    int x = query(2*index+1, low, mid, l, r);
    // Traverse to right child
    int y = query(2*index+2, mid+1, high, l, r);
    // return the maximum value obtained from the left and right child of this particular index int the segment tree.
    return max(x, y);
}

// Recursive function to create segement tree in O(n * 4) ≅ O(n)
// Observe, this funciton is very similar to mergeSort's splitting funciton.
void build(int index, int low, int high){
    // base case
    if(low == high){
        seg[index] = arr[low];
        return;
    }
    int mid = (low + high)/2;
    // build the left child
    build(2*index+1, low, mid);
    // build the right child
    build(2*index+2, mid + 1, high);
    // backtrack in the end and store the maximum value of the left and right child to this index in the segment tree.
    seg[index] = max(seg[2*index+1], seg[2*index+2]);
}

int main(){
    // Build the segment tree first
    build(0, 0, n - 1);
    // Query to find the maximum the element in array from index 0 to 1 
    cout << query(0, 0, n-1, 0, 1) << '\n';
    // Query to find the maximum the element in array from index 2 to 6
    cout << query(0, 0, n-1, 2, 6) << '\n';
    // Query to find the maximum the element in array from index 0 to 6
    cout << query(0, 0, n-1, 0, 6) << '\n';
    // Query to find the maximum the element in array from index 5 to 7
    cout << query(0, 0, n-1, 5, 7) << '\n';
    return 0;
}


// Time Complexity = O(n) + O(q * log(n))
// Space Complexity = O(4*n) = O(n)
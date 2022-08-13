#include<bits/stdc++.h>
using namespace std;
int main(){

    int arr[] = {2,0,0,1,2,2,1,0,0,1};
    int len = *(&arr + 1) - arr;
    int low = 0, mid = 0, high = len - 1;

    while(mid <= high){
        switch(arr[mid]){
            case 2: swap(arr[mid], arr[high--]);
                    break;
            case 0: swap(arr[mid++], arr[low++]);
                    break;
            case 1: mid++;
        }
    }

    for(int i = 0; i < len; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
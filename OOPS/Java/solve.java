import java.util.*;
class Solve{
    static int findMax(int arr[], int index, int sum, int n){
        if(index >= n){
            return sum;
        }
        int l = findMax(arr, index + 1, sum, n);
        int r = findMax(arr, index + 2, sum + arr[index], n);
        return Math.max(l, r);
    }

    public static void main(String args[]){
        int arr[] = new int[]{1, 2, 8, 3, 12, 14, 4};
        System.out.println(findMax(arr, 0, 0, arr.length));
    }
}
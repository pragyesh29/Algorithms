import java.util.Scanner;
class Reverse{
    static Scanner sc = new Scanner(System.in);
    
    // method to reverse the array elements from give start position to end position
    private static void rev(int[] arr, int start, int end){
        while(start < end){
            arr[start] += arr[end];
            arr[end] = arr[start] - arr[end];
            arr[start] -= arr[end];
            start++; end--;
        }
    }

    // Reverse Algo: implementation (TO ROTATE LEFT)
    private static void reverseAlgo(int[] arr, int k){
        // TO ROTATE RIGHT uncomment following line
        // k = arr.length - k;
        Reverse.rev(arr, 0, k-1);
        Reverse.rev(arr, k, arr.length-1);
        Reverse.rev(arr, 0, arr.length-1);
    }

    // method to fill the data from user's input
    private static void getArrInput(int[] arr){
        for(int i=0; i<arr.length; i++){
            arr[i] = sc.nextInt();
        }
    }
    // method to print the contents of the array
    private static void printArr(int[] arr){
        for(int i: arr){
            System.out.print(i + " ");
        }
    }
    
	// main method
	public static void main(String[] args){
		// Get number of array elements from user.
		int N = sc.nextInt();
		// Get number of times rotations had to be performed. 
		int k = sc.nextInt();
		k %= N;
		int arr[] = new int[N];
		Reverse.getArrInput(arr);
        Reverse.reverseAlgo(arr, k);
		Reverse.printArr(arr);
	}
}
import java.util.Scanner;
class MainClass{
	static Scanner sc = new Scanner(System.in);
	// method to calculate gcd of two numbers
	private static int gcd(int a, int b){
		return (b == 0) ? a : gcd(b, a%b);
	}

	// juggling algorithm: implementation (TO ROTATE LEFT)
	private static void juggle(int[] arr, int k){
		int n = arr.length;
		// calculating hcf for array elements and number of rotations need to be performed.
		// TO ROTATE RIGHT uncomment the following line
		// k = n - k;
		int hcf = gcd(n, k);
		for(int i=0; i<hcf; i++){
			int j = i;
			int temp = arr[i];
			while(true){
				// calculating index of element ahead k steps, to which arr[j] should be swapped.
				int d = (j + k) % n;
				// if d evaluates to become to equal to i then we have completed one rotation.
				if(d == i) {
					arr[j] = temp;
					break;
				}
				// storing the value of corresponding element in the set ahead.
				arr[j] = arr[d];
				// update j to move d steps ahead i.e. move to the set ahead.
				j = d;
			}
		}
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
		MainClass.getArrInput(arr);
		MainClass.juggle(arr, k);
		MainClass.printArr(arr);
	}
}
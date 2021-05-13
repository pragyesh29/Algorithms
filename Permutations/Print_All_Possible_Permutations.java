import java.util.*;
class AllPermutations{
    
    // Method to print all possible permutations of the given String.
    // This method does not check for the duplicate elements.
    // This metho uses backtracking to achieve the desired result.
    
    // Example
    // I/P - ABC
    // O/P - ABC ACB BAC BCA CAB CBA
    private static void permuteAll(char[] str, int start, int end){

        // Base condition
        if(start == end){
            System.out.println(new String(str));
        }else{
            for(int i=start; i<end; i++){
                // backtraking, to restore the array's form.
                swap(str, start, i);
                permuteAll(str, start+1, end);
                swap(str, start, i);
            }
        }
    }

    // Method to swap two characters in the character array i.e. String
    private static void swap(char[] str, int a, int b){
        char c = str[a];
        str[a] = str[b];
        str[b] = c;
    }

    // Driver to test the above algorithm
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        char str[] = s.toCharArray();
        permuteAll(str, 0, s.length());
    }
}
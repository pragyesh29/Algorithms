import java.util.*;
class Array{

    static void print(int arr[][], int row, int col){
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
    }

    boolean flag;
    static void doOperation(int arr[][], int row, int col){
        for(int i = 1; i < row; i++){
            for(int j = 1; j < col; j++){
                if(arr[i][j] == 0){
                    arr[i][0] = -1;
                    arr[0][j] = -1;
                }
            }
        }
        for(int i = 0; i < row; i++){
            if(arr[i][0] == 0){
                arr[i][0] = -1;
                rowflag = true;
            }
        }
        for(int j = 0; j < col; j++){
            if(arr[0][j] == 0){
                arr[0][j] = -1;
                colflag = true;
            }
        }
        for(int i = 1; i < row; i++){
            if(arr[i][0] == -1){
                for(int j = 0; j < col; j++){
                    arr[i][j] = 0;
                }
            }
        }
        for(int i = 0; i < col; i++){
            if(arr[0][i] == -1){
                for(int j = 0; j < row; j++){

                }
            }
        }
    }

    public static void main(String args[]){
        int row = 3, col = 3;
        int arr[][] = new int[row][];
        arr[0] = new int[]{1, 0, 4};
        arr[1] = new int[]{5, 23, 0};
        arr[2] = new int[]{8, 43, 24};
        print(arr, row, col);
        System.out.println();
        doOperation(arr, row, col);
        print(arr, row, col);
    }
}
#include<iostream>
#include<conio.h>
#include<vector>
#include<math.h>
using namespace std;

class SquareMatrix{
    int row, col;
    friend void additionOfTwoMatrix(SquareMatrix &obj1, SquareMatrix&obj2);
    friend void determinantOfMatrix(SquareMatrix &obj);
    public:
    vector<vector<double>> matrix;
    vector<vector<double>> tmp;
    double determinant;
    // Parameterized Constructor
    SquareMatrix(int row, int col){
        this->row = row;
        this->col = col;
        for(int i = 0; i < row; i++){
            vector<double> tmp(col, 0.0d);
            matrix.push_back(tmp);
        }
    }

    // Member function to get input of elements in matrix
    void getInput(){
        for(int i = 0; i < this->row; i++){
            for(int j = 0; j < this->col; j++){
                cout << "Enter element at matrix[" << i << "][" << j << "] : ";
                cin >> matrix[i][j];
            }
        }
        printMatrix();
    }

    // Member function to print the Matrix
    void printMatrix(){
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                cout << matrix[i][j] << " ";
            }
            cout << '\n';
        }
    }
};

// Member function to print the addition of two Matrix
void additionOfTwoMatrix(SquareMatrix &obj1, SquareMatrix &obj2){
    if(obj1.row == obj2.row && obj1.col == obj2.col){
        for(int i = 0; i < obj1.row; i++){
            for(int j = 0; j < obj1.col; j++){
                cout << obj1.matrix[i][j] + obj2.matrix[i][j] << " ";
            }
            cout << '\n';
        }
    }else{
        cout << "For addtion of two matrix the dimention of both the matrices must be same\n";
    }
}

// Member function to print the determinant of a Matrix
void determinantOfMatrix(SquareMatrix &obj){
    int row = obj.matrix.size(), col = obj.matrix[0].size();
    if(row != col){
        cout << "For existance of determinant, matrix must be square matrix.\n";
        return;
    }
    if(row > 3 || col > 3){
        cout << "Dimentions of obj.matrix can be at most 3x3\n";
        return;
    }
    if(row == 1) obj.determinant = obj.matrix[0][0];
    if(row == 2) obj.determinant = ((obj.matrix[0][0] * obj.matrix[1][1]) - (obj.matrix[0][1] * obj.matrix[1][0]));
    if(row == 3) obj.determinant = ((obj.matrix[0][0]*(obj.matrix[1][1]*obj.matrix[2][2] - obj.matrix[2][1]*obj.matrix[1][2]))
                        -(obj.matrix[0][1]*(obj.matrix[1][0]*obj.matrix[2][2] - obj.matrix[1][2]*obj.matrix[2][0]))
                        +(obj.matrix[0][2]*(obj.matrix[1][0]*obj.matrix[2][1] - obj.matrix[2][0]*obj.matrix[1][1])));
}

int main(){
    SquareMatrix obj1(3,3);
    obj1.getInput();
    determinantOfMatrix(obj1);
    cout << obj1.determinant << '\n';
    return 0;
}
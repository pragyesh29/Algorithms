#include<iostream>
using namespace std;
class Complex{
    int real, imaginary;
    friend Complex addComplexNumber(Complex &first, Complex &second);
    friend void displayResultantComplexNumber(Complex &obj);
    public:
    Complex(){
        this->real = 0;
        this->imaginary = 0;
    }
    Complex(int val){
        this->real = this->imaginary = val;
    }
    Complex(int real, int imaginary){
        this->real = real;
        this->imaginary = imaginary;
    }
};

Complex addComplexNumber(Complex &first, Complex &second){
    Complex res;
    res.real = first.real + second.real;
    res.imaginary = first.imaginary + second.imaginary;
    cout << "Numbers added Successfully!!\n";
    return res;
}

void displayResultantComplexNumber(Complex &obj){
    cout << obj.real << "+" << obj.imaginary << "i\n";
}

int main(){
    Complex obj1(3);
    displayResultantComplexNumber(obj1);
    Complex obj2(5, 2);
    displayResultantComplexNumber(obj2);
    Complex res = addComplexNumber(obj1, obj2);
    displayResultantComplexNumber(res);
    return 0;
}
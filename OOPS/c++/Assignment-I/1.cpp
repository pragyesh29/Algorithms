#include<iostream>
using namespace std;
class Largest{
    int a, b, c, result;
    public:
    void input(){
        cout << "Enter first number : ";
        cin >> a;
        cout << "Enter second number : ";
        cin >> b;
        cout << "Enter third number : ";
        cin >> c;
    }
    void largest(){
        if(a > b && a > c) result = a;
        else if(b > a && b > c) result = b;
        else result = c;
    }
    void output(){
        cout << "Largest numbers among all three is : " << result << '\n';
    }
};

int main(){
    Largest obj;
    obj.input();
    obj.largest();
    obj.output();
    return 0;
}
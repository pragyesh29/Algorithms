#include<iostream>
using namespace std;
class Student{
    int marks;
    public:
    Student(int x){
        marks = x;
    }
    Student(Student &x){
        marks = x.marks;
    }
    void show_marks(){
        cout << marks << '\n';
    }
};
int main(){
    Student obj1(34);
    Student obj2 = obj1;
    obj2.show_marks();
    return 0;
}
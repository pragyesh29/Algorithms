#include<iostream>
using namespace std;
class Time{
    int hour, minute;
    public:
    void getTime(){
        cout << "Enter hour : ";
        cin >> hour;
        cout << "Enter minutes : ";
        cin >> minute;
    }
    void sum(Time obj1){
        this->hour += obj1.hour;
        this->minute += obj1.minute;
        if(this->minute >= 60){
            this->hour += (this->minute / 60);
            this->minute %= 60;
        }
    }
    void display(){
        cout << "Resultant time\n";
        cout << this->hour << " hours " << this->minute << " minutes\n";
    }
};
int main(){
    Time obj1;
    obj1.getTime();
    Time obj2;
    obj2.getTime();
    obj1.sum(obj2);
    obj1.display();
    return 0;
}
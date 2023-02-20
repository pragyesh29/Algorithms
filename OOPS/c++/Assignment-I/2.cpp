#include<iostream>
using namespace std;
class Bank_Account{
    string account_number, type, name;
    double balance;
    public:
    Bank_Account(string name, string type, string account_number, double balance){
        this->name = name;
        this->type = type;
        this->account_number = account_number;
        this->balance = balance;
    }

    void current_balance(){
        cout << "Current Balance is : " << balance << '\n';
    }

    void deposit(){
        double tmp;
        cout << "Enter the amount to deposit : ";
        cin >> tmp;
        balance += tmp;
        current_balance();
    }

    void withdraw(){
        double tmp;
        cout << "Enter the amount to be withdrawn : ";
        cin >> tmp;
        balance -= tmp;
        current_balance();
    }
};
int main(){
    Bank_Account obj("Aakash", "Saving", "23242488294004", 22424.524);
    obj.current_balance();
    obj.deposit();
    obj.withdraw();
    return 0;
}
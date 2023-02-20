#include<iostream>
using namespace std;
class Bank_Account{
    string credential_user_id = "Pragyesh19", credential_password = "Garbage123456";
    string user_id, password;
    public:
    double balance;
    Bank_Account(string user_id, string password){
        this->user_id = user_id;
        this->password = password;
    }
    bool authenticate(){
        if(user_id == credential_user_id){
            if(password == credential_password){
                cout << "Successfully Logged In...\n";
                return true;
            }else{
                cout << "Wrong password please try again\n";
                return false;
            }
        }else{
            cout << "Wrong User Id\n";
            return false;
        }
    }
    void withdrawMoney(){
        double tmp;
        cout << "Enter the money to be withdrawn : ";
        cin >> tmp;
        balance -= tmp;
    }
    void depositMoney(){
        double tmp;
        cout << "Enter the money to be deposited : ";
        cin >> tmp;
        balance += tmp;
    }
    void displaybalance(){
        cout << "Current Remaining balance is : " << balance << '\n';
    }
};
int main(){
    string username, password;
    cout << "Login\n";
    cout << "Enter username : ";
    cin >> username;
    cout << "Enter password : ";
    cin >> password;
    Bank_Account obj(username, password);
    if(obj.authenticate()){
        while(1){
            int ch;
            cout << "Enter 1 to deposit\n";
            cout << "Enter 2 to withdraw\n";
            cout << "Enter 3 to display current balance\n";
            cout << "Enter 4 to terminate the program\n";
            cout << "Enter choice : ";
            cin >> ch;
            if(ch == 4) break;
            switch(ch){
                double tmp;
                case 1: cout << "Enter the amount to deposit : ";
                        cin >> tmp;
                        obj.balance += tmp;
                        obj.displaybalance();
                        break;
                case 2: cout << "Enter the amount to withdraw : ";
                        cin >> tmp;
                        obj.balance -= tmp;
                        obj.displaybalance();
                        break;
                case 3: obj.displaybalance();
                        break;
            }
            cout << "-------------------------------------------------\n";
        }
    }else{
        main();
    }
    return 0;
}
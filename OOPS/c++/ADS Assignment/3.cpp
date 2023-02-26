#include<iostream>
#include<cassert>
using namespace std;
class Array{
    int n;
    int *arr;
    public:
    Array(int n){
        this->n = n;
        arr = new int[n];
    }
    void insert(int, int);
    void display();
    void getsize();
    void deleteElement(int);
};

void Array::getsize(){
    cout << n << endl;
}

void Array::display(){
    for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
    }
    cout << endl;
}

void Array::insert(int data, int index){
    assert(index >= 0 && index < n);
    arr[index] = data;
}

void Array::deleteElement(int index){
    assert(index >= 0 && index < n);
    for(int i = index; i < n-1; i++){
        arr[i] = arr[i+1];
    }
    n--;
    cout << "Array after deletion of element at index " << index << " is : ";
    display();
}

int main(){
    cout << "Enter n : ";
    int n; cin >> n;
    Array arr(n);
    system("cls");
    cout << "Array object with named arr has been created with size " << n << '\n';
    cout << "\nPress any key to continue...";
    system("cls");
    int ch;
    while(ch != 5){
        cout << "Enter 1 to insert into array created\n";
        cout << "Enter 2 to display the data of array\n";
        cout << "Enter 3 to get the size of the array\n";
        cout << "Enter 4 to get the size of the array\n";
        cout << "Enter 5 to terminate the program\n";
        cout << "Enter choice: ";
        cin >> ch;
        switch(ch){
            case 1: int index, data;
                    cout << "Enter index at which data is needed to be inserted : ";
                    cin >> index;
                    cout << "Enter data to be inserted at index " << index << " : ";
                    cin >> data;
                    arr.insert(data, index);
                    cout << "Data inserted successfully...\n";
                    system("pause");
                    system("cls");
                    break;
            case 2: arr.display();
                    system("pause");
                    system("cls");
                    break;
            case 3: arr.getsize();
                    system("pause");
                    system("cls");
                    break;
            case 4: cout << "Enter the index of which element is needed to delete : ";
                    int ind; cin >> ind;
                    arr.deleteElement(ind);
                    system("pause");
                    system("cls");
                    break;
            case 5: break;
        }
    }
    return 0;
}
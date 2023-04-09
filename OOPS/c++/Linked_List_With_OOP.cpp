#include<iostream>
using namespace std;

class Node{
    public:
    string val;
    Node* next;
    Node(){
        val = "";
        next = NULL;
    }

    Node(string val){
        this->val = val;
        next = NULL;
    }
};
class LinkedList{
    public:
    int size;
    Node* head;
    LinkedList(){
        head = NULL;
        size = 0;
    }
    bool insertIntoList();
    bool deleteFromList();
    void displayTheList();
    bool deleteList();
    void reverseList();
    void listLeftShift();
};

bool LinkedList :: insertIntoList(){
    cout << "Enter index at which node is to be inserted : ";
    int index; cin >> index;
    if(index < 0 || index > this->size){
        cout << "Invalid index : Index must in range [0," << this->size << "]\n";
        return false;
    }
    cout << "Enter the data of the node : ";
    string data; cin >> data;
    Node* newnode = new Node(data);
    if(index == 0){
        if(this->head == NULL) this->head = newnode;
        else{
            newnode->next = this->head;
            this->head = newnode;
        }
    }else if(index == this->size){
        Node* tmp = this->head;
        while(tmp->next){
            tmp = tmp->next;
        }
        tmp->next = newnode;
    }else{
        Node* tmp = this->head;
        int j = 0;
        while(j < index-1){
            tmp = tmp->next;
            j++;
        }
        Node* ptr = tmp->next;
        tmp->next = newnode;
        newnode->next = ptr;
    }
    this->size++;
    return true;
}

void LinkedList :: displayTheList(){
    Node* tmp = this->head;
    while(tmp){
        if(tmp->next) cout << tmp->val << "->";
        else cout << tmp->val;
        tmp = tmp->next;
    }
    cout << '\n';
}

bool LinkedList :: deleteFromList(){
    cout << "Enter to index of the node which is to be deleted : ";
    int index; cin >> index;
    if(index == 0){
        if(this->size > 0){
            Node *ptr = this->head;
            head = head->next;
            delete ptr;
        }else{
            cout << "List is already empty!!";
            return false;
        }
    }else{
        int j = 0;
        Node *ptr = this->head;
        while(j < index-1){
            ptr = ptr->next;
            j++;
        }
        Node* ptr2 = ptr->next;
        ptr->next = ptr2->next;
        delete ptr2;
    }
    this->size--;
    return true;
}

bool LinkedList :: deleteList(){
    delete[] this->head;
    this->head = NULL;
    this->size = 0;
    return true;
}

void LinkedList :: reverseList(){
    Node* tmp = this->head;
    Node* rev = NULL;
    while(tmp){
        Node* ptr = tmp;
        tmp = tmp->next;
        ptr->next = rev;
        rev = ptr;
    }
    this->head = rev;
}

void LinkedList :: listLeftShift(){
    cout << "Enter number of times list list to be rotated left : ";
    int m; cin >> m;
    int n = this->size;
    m %= n;
    Node* i = this->head;
    for(; m > 1; m--){
        i = i->next;
    }
    Node* ptr = i->next;
    i->next = NULL;
    Node* tmp = ptr;
    while(tmp->next){
        tmp = tmp->next;
    }
    tmp->next = this->head;
    this->head = ptr;
}

int main(){
    LinkedList list;
    int ch;
    while(ch != 6){
        cout << "Press 1 to insert node\n";
        cout << "Press 2 to delete node\n";
        cout << "Press 3 to display linked list node\n";
        cout << "Press 4 to get size of linked list\n";
        cout << "Press 5 to delete the list \n";
        cout << "Press 6 to reverse the list\n";
        cout << "Press 7 to left shift the list\n";
        cout << "Press 10 to terminate the program \n";
        cout << "Enter choice : ";
        cin >> ch;
        switch(ch){
            int index, data;
            case 1: if(!list.insertIntoList()) cout << "Insertion Failed\n";
                    break;
            case 2: if(!list.deleteFromList()) cout << "Deletion Failed\n";
                    break;
            case 3: cout << "__List_is__\n";
                    list.displayTheList();
                    break;
            case 4: cout << "Current size of list is : " << list.size << '\n';
                    break;
            case 5: if(list.deleteList()) cout << "List deleted successfully!\n";
                    break;
            case 6: list.reverseList();
                    break;
            case 7: list.listLeftShift();
                    break;
            case 10: return 0;
        }
        system("pause");
        system("cls");
    }
    return 0;
}
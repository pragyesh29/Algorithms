#include<iostream>
#include<conio.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(){
        data = 0;
        next = NULL;
    }

    Node(int data){
        this->data = data;
        next = NULL;
    }
};
class LinkedList{
    Node* head;
    public:
    LinkedList(){
        head = NULL;
    }
    void insertIntoList(int);
    void displayNodes();
    void deleteFromList();
};
void LinkedList :: insertIntoList(int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
    }else{
        Node* tmp = head;
        while(tmp->next){
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
}
void LinkedList :: displayNodes(){
    Node* tmp = head;
    while(tmp){
        if(tmp->next) cout << tmp->data << "->";
        else cout << tmp->data << '\n';
        tmp = tmp->next;
    }
}
void LinkedList :: deleteFromList(){
    cout << "Enter the value of node to delete : ";
    int data; cin >> data;
    if(head->data == data){
        head = head->next;
    }else{
        Node* tmp = head;
        while(tmp->next){
            if(tmp->next->data == data){
                tmp->next = tmp->next->next;
                break;
            }
            tmp = tmp->next;
        }
    }
}
int main(){
    LinkedList list;
    cout << "Enter number of nodes : ";
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        list.insertIntoList(x);
    }
    list.displayNodes();
    list.deleteFromList();
    list.displayNodes();
    return 0;
}
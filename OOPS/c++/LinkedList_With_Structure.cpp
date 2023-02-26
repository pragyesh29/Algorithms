#include<iostream>
using namespace std;
struct node{
    int val;
    struct node* next;
};

struct node* createNode(int data){
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    tmp->val = data;
    tmp->next = NULL;
    return tmp;
}

struct node* addNode(struct node* root, int data){
    if(!root){
        root = createNode(data);
    }else{
        struct node* tmp = root;
        while(tmp->next){
            tmp = tmp->next;
        }
        tmp->next = createNode(data);
    }
    return root;
}

void display_List(struct node* root){
    struct node* tmp = root;
    while(tmp){
        if(!tmp->next) cout << tmp->val << '\n';
        else cout << tmp->val << "->";
        tmp = tmp->next;
    }
}

int main(){
    int n;
    cout << "Enter number of nodes : ";
    cin >> n;
    struct node* root = NULL;
    for(int i = 0; i < n; i++){
        int data;
        cout << "Enter data : ";
        cin >> data;
        root = addNode(root, data);
    }
    display_List(root);
}
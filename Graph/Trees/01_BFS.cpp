#include<bits/stdc++.h>
using namespace std;

// Definition of each Node
struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode* right): val(x), left(left), right(right) {}
};

// BFS
vector<vector<int>> BFS(TreeNode* root){
    vector<vector<int>> res;
    if(!root) return res;
    queue<TreeNode*> q;
    q.emplace(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> tmp;
        for(int i = 0; i < size; i++){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left) q.emplace(curr->left);
            if(curr->right) q.emplace(curr->right);
            tmp.push_back(curr->val);
        }
        res.push_back(tmp);
    }
    return res;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    vector<vector<int>> res = BFS(root);
    for(vector<int> i : res){
        for(int j : i){
            cout << j << " ";
        }
        cout << '\n';
    }
    return 0;
}
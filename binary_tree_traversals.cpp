#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        left = right = NULL;
    }
};

void in_order(Node* root){
    if(root == NULL){
        return;
    }
    in_order(root->left);
    cout << root->val << " ";
    in_order(root->right);
}

void pre_order(Node* root){
    if(root == NULL){
        return;
    }
   cout << root->val << " ";
   pre_order(root->left);
   pre_order(root->right);
}

void post_order(Node* root){
    if(root == NULL){
        return;
    }
    post_order(root->right);
    post_order(root->left);
    cout << root->val << " "; 
}

void level_order(Node* root){
    queue<Node *> q;
    if(root == NULL){
        return;
    }
    q.push(root);
    while(q.size()!=0){
        Node* x = q.front();
        q.pop();
        cout << x->val << " ";
        if(x->left!=NULL)
            q.push(x->left);
        if(x->right!=NULL)
            q.push(x->right);
    }
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(12);
    root->right = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(5);
    root->right->left = new Node(20);
    root->right->right = new Node(15);

    cout << "In order Traveral of the tree -> " ;
    in_order(root);
    cout << endl ;
    cout << "Pre order Traveral of the tree -> " ;
    pre_order(root);
    cout << endl;
    cout << "Post order Traveral of the tree -> " ;
    post_order(root);
    cout << endl;
    cout << "Level order Traveral of the tree -> " ;
    level_order(root);
    cout << endl;

    return 0;
}

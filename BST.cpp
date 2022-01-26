#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(){ val = 0; left = right = NULL;}
    Node (int val){this->val = val; left = right =NULL;}
};

class BinaryTree{
    Node* root;
    void insert(Node* tree_node,int data);
    bool search(Node* tree_node,int data);
    Node* find(Node* tree_node, int data);
    Node* maxVal(Node* tree_node);
    Node* minVal(Node* tree_node);
//    void destroy(Node* root);
    Node* delete_node(Node* tree_node,int data);
    void in_order(Node* tree_node);

public:

    BinaryTree(){this->root = NULL;}
//    ~BinaryTree(){ destroy(root);}
    void insert(int data){ insert(root,data);};
    bool search(int data){ return search(root,data);};
    Node* find(int data){ return find(root,data);};
    Node* maxVal(){ return maxVal(root);};
    Node* minVal(){return maxVal(root);};
//    void destroy(Node* root);
    void delete_node(int data){root = delete_node(root,data);};
    void in_order(){in_order(root);};
};

bool BinaryTree:: search(Node* tree_node,int data){
    if(tree_node == NULL)
        return false;
    if(data == tree_node->val)
        return true;
    else if(data < tree_node->val){
        return search(tree_node->left,data);
    }
    else{
        return search(tree_node->right,data);
    }
}

Node* BinaryTree:: maxVal(Node* tree_node){
    if(tree_node == NULL)
        return NULL;
    Node* current = tree_node;
    while(current->right!=NULL){
        current = current->right;
    }
    return current;
}

Node* BinaryTree:: minVal(Node* tree_node){
    if(tree_node == NULL)
        return NULL;
    Node* current = tree_node;
    while(current->left!=NULL){
        current = current->left;
    }
    return current;
}

void BinaryTree:: insert(Node* tree_node,int data){
    if(tree_node == NULL){
        Node* nw = new Node(data);
        root = nw;
    }
    else {
        if (data < tree_node->val){
            if(tree_node->left == NULL){
                Node* nw = new Node(data);
                tree_node->left = nw;     
            }
            else
                insert(tree_node->left,data);
        }
        else{
            if(tree_node->right == NULL){
                Node* nw = new Node(data);
                tree_node->right = nw;          
            }
            else
                insert(tree_node->right,data);
        }
    }
}

Node* BinaryTree:: find(Node* tree_node,int data){
    if(!search(tree_node,data)){
        return NULL;
    }
    if(data == tree_node->val){
        return tree_node;
    }
    else if(data < tree_node->val){
        return find(tree_node->left,data);
    }

    else{
        return find(tree_node->right,data);
    }
}
Node* BinaryTree:: delete_node(Node* tree_node,int data){
    if(tree_node == NULL){
        cout << "The element is not present in the tree" << endl;
        return NULL;
    }
    if(data == tree_node->val){
        if(tree_node->left == NULL && tree_node->right == NULL){
            return NULL;
        }
        else if(tree_node->left!=NULL){
            return tree_node->left;
        }
        else if(tree_node->right!=NULL){
            return tree_node->right;
        }
        else{
            Node* minright = minVal(tree_node->right);
            tree_node->val = minright->val;
            tree_node->right = delete_node(tree_node->right,minright->val);
        }
    }
    else if(data < tree_node->val)
        tree_node->left = delete_node(tree_node->left,data);
    else
        tree_node->right = delete_node(tree_node->right,data);
    return tree_node;
}

void BinaryTree:: in_order(Node* tree_node){
    if(tree_node == NULL){
        return;
    }
    in_order(tree_node->left);
    cout << tree_node->val << " ";
    in_order(tree_node->right);
}

int main(){
    BinaryTree mytree;
    mytree.insert(10);
    mytree.insert(20);
    mytree.insert(5);
    mytree.insert(7);
    mytree.in_order();
    cout << endl;
    mytree.delete_node(20);
    mytree.delete_node(5);
    mytree.in_order();
    return 0;
}




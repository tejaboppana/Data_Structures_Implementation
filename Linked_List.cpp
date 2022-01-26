#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    Node * next;
    int val;
    //Default constructor 
    Node(){
        val = 0;
        next = NULL;
    }

    //Parameteried Constriuctor
    Node(int data){
        val = data;
        next = NULL;
    }
};

class LinkedList{
    Node* head;
public:
    LinkedList(){head = NULL;}

    //function to insert a node at the end of the list 
    void insertNode(int);
    //Function to delete a node at given position
    void deleteNode(int);
    //function to print the linked list 
    void printList();
    // function to search an element in the Linked list
    bool searchNode(int);

};

void LinkedList:: insertNode(int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void LinkedList:: deleteNode(int nodeOffset){
    if(head == NULL){
        cout << "The Linked List is empty";
        return;
    }
    Node* temp1 = head;
    Node* temp2 = NULL;
    int len = 0;
    while(temp1!=NULL){
        temp1 = temp1->next;
        len++;
    }
    if(nodeOffset > len){
        cout<<"Index to be deleted is out of range";
        return;
    }

    temp1 = head;

    if(nodeOffset == 1){
        head = head->next;
        delete temp1;
        return;
    }

    while(nodeOffset > 1){
        temp2 = temp1;
        temp1 = temp1->next;
        nodeOffset--;
    }

    temp2->next = temp1->next;
    delete temp1;
}

void LinkedList:: printList(){

    if(head == NULL){
        cout << "The List is empty";
        return;
    }

    Node* temp = head;
    while(temp->next!=NULL){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout << temp->val;
}

bool LinkedList:: searchNode(int data){
    if(head == NULL){
        cout << "The List is empty";
        return false;       
    }
    Node* temp = head;
    while(temp!=NULL){
        if(temp->val == data){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main(){
    LinkedList list;
    list.insertNode(5);
    list.insertNode(4);
    list.insertNode(10);
    list.insertNode(12);
    list.insertNode(1);
    list.insertNode(20);

    cout << "Elements of the list are: ";
    list.printList();
    cout << endl;

    list.deleteNode(1);

    if(list.searchNode(20)){
        cout << "Number 20 is present in the list";
    }
    else {
        cout << "Number 20 is not present in the list";
    }

    cout << endl;

    if(list.searchNode(1)){
        cout << "Number 1 is present in the list";
    }
    else{
        cout << "Number 1 is not present in the list";
    }
    return 0;
}
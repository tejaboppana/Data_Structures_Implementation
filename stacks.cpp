#include <bits/stdc++.h>
using namespace std;
class Stack{
    int top;
    int size;
public:
    int *a;
    Stack(){
        top = -1; 
        size = 10;
        a = new int[size];
    }
    Stack(int size){
        this->top = -1;
        this->size = size;
        a = new int[size];
    }

    ~Stack(){
        delete [] a;
    }
    void push(int data);
    bool isEmpty();
    int pop();
    int top_stack();
};

void Stack::push(int data){
    if(top >= size-1){
        cout << "Stack is full";
        return ;
    }
    else{
        a[++top]= data;
        cout <<"Pushed " << data << " successfully to the stack" << endl;
    }  
}

bool Stack::isEmpty(){
    if(top < 0)
        return true;
    else
        return false;
}

int Stack:: pop(){
    if(top < 0){
        cout << "The stack is empty";
        return -1;
    }
    else{
        return a[top--];
    }
}
 int Stack:: top_stack(){
     if(top < 0){
         cout << "The stack is empty";
         return -1;
     }
     else{
         return a[top];
     }
 }

 int main(){
     Stack mystack(100);
    if(mystack.isEmpty()){
        cout << "The stack is empty" << endl;
    }
    else{
        cout << "The stack is not empty" << endl;
    }
     mystack.push(13);
     mystack.push(20);
     mystack.push(3);
     mystack.push(200);

    cout << mystack.top_stack() << endl;
    cout << mystack.pop() << endl;
    cout << mystack.top_stack() << endl;
    if(mystack.isEmpty()){
        cout << "The stack is empty" << endl;
    }
    else{
        cout << "The stack is not empty" << endl;
    }
 }
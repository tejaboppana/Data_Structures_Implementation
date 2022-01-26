#include <bits/stdc++.h>
using namespace std;

class Queue{
    int *a;  // array to store elements 
    int front; // front of the queue 
    int rear; // rear of the queue where items have to be added 
    int capacity; // max capacity of the queue
    int size; // current size of the queue 

public:
    Queue(){
        int front = 0;
        int rear = -1;
        int capacity = 1;
        int size = 0;
        a = new int[capacity];
    }
    Queue(int capacity){
        front = 0;
        rear = -1;
        this->capacity = capacity;
        size = 0;
        a = new int[capacity];
    }

    ~Queue(){
        delete [] a;
    }

    bool isEmpty();
    bool isFull();
    void enqueue(int data);
    int dequeue();
    int front_element();
    int queue_size();

};

int Queue:: queue_size(){
    return size;
}

bool Queue:: isEmpty(){
    if(queue_size() == 0){
        return true;
    }
    else{
        return false;
    }
}

bool Queue:: isFull(){
    if(queue_size()==capacity){
        return true;
    }
    else {
        return false;
    }
}

void Queue:: enqueue(int data){
    if(isFull()){
        cout << "The Queue is full" << endl;
        return;
    }
    else{
        rear = (rear+1)%capacity;
        a[rear] = data;
        size++;
        cout << "Successfully added " << data << " to the queue" << endl;
    }
}

int Queue:: dequeue(){
    if(isEmpty()){
        cout << "The queue is empty" << endl;
        return -1;
    }
    else{
        int x = a[front];
        cout << "Successfully removed " << x << " from the queue" << endl;
        front = (front+1)%capacity;
        size--;
        return x;
    }
}

int Queue:: front_element(){
    if(isEmpty()){
        cout << "The Queue is empty" << endl;
        exit(EXIT_FAILURE);
    }
    return a[front];
}

int main(){
    Queue myqueue(5);
    if(myqueue.isEmpty()){
        cout << "Queue is empty" << endl;
    }
    myqueue.enqueue(3);
    myqueue.enqueue(1);
    myqueue.enqueue(10);
    cout << "Front element is " << myqueue.front_element() << endl;
    myqueue.enqueue(8);
    myqueue.enqueue(20);
    myqueue.enqueue(13);
    myqueue.dequeue();
    cout << "Front element is " << myqueue.front_element() << endl;
    return 0;
}

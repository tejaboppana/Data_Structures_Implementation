#include <bits/stdc++.h>
using namespace std;

class MaxHeap{
    int * arr;
    int capacity;
    int size;
public:
    MaxHeap(){
        capacity = 1;
        size = 0;
        arr = new int [capacity];
    }
    MaxHeap(int capacity){
        this->capacity = capacity;
        size = 0;
        arr = new int [capacity];
    }
    ~MaxHeap(){
        delete [] arr;
    }
    int heap_size();
    bool isEmpty();
    bool isFull();
    void insert(int data);
    int delete_element();
    int max_element();
    void maxheapify(int index, int size);
    void upheapify(int index);
};

int MaxHeap:: heap_size(){
    return size;
}

bool MaxHeap:: isEmpty(){
    return heap_size()==0;
}

bool MaxHeap:: isFull(){
    if(size == capacity)
        return true;
    else   
        return false;
}

void MaxHeap:: insert(int data){
    if(isFull()){
        cout << "The Heap is full" << endl;
        return ;
    }
    size++;
    arr[size-1] = data;
    upheapify(size-1);
    cout << "Element " << data << " has been added successfully" << endl;
}

int MaxHeap:: delete_element(){
    if(isEmpty()){
        cout << "The heap is empty" << endl;
        return -1;
    }
    int x = arr[0];
    arr[0] = arr[size-1];
    cout << "The element " << x << " has been removed" << endl;
    size--;
    maxheapify(0,size);
    return x; 
}

int MaxHeap:: max_element(){
    if(isEmpty()){
        cout << "The heap is empty" << endl;
        return -1;
    }
    return arr[0];
}

void MaxHeap:: maxheapify(int index, int size){
    int left = 2*index;
    int right = 2*index + 1;
    if(left >= size && right >=size)
        return;
    int max_index = index;
    if(arr[left] > arr[max_index] && left < size){
        max_index = left; 
    }
    if(arr[right] > arr[max_index] && right < size){
        max_index = right; 
    }
    if(max_index != index){
        int temp = arr[max_index];
        arr[max_index] = arr[index];
        arr[index] = temp;
        maxheapify(max_index,size);
    }
    return;
}

void MaxHeap:: upheapify(int index){
    int parent = floor((index-1)/2);
    if(parent < 0)
        return;
    else{
        if (arr[parent] < arr[index]){
            int temp = arr[parent];
            arr[parent] = arr[index];
            arr[index] = temp;
            upheapify(parent);
        }
        else
            return; 
    }
}

int main(){
    MaxHeap myheap(6);
    myheap.delete_element();
    if(myheap.isEmpty()){
        cout << "The heap is empty" << endl;
    }
    myheap.insert(2);
    myheap.insert(1);
    myheap.insert(4);
    myheap.insert(10);
    myheap.insert(50);
    myheap.insert(4);
    myheap.insert(4);
    cout << "Max element now is " <<  myheap.max_element() << endl;
    myheap.delete_element();
    cout << "Max element now is " <<  myheap.max_element() << endl;
     return 0;
}


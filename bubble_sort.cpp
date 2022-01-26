#include <bits/stdc++.h>
using namespace std;

void swap(int*a , int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(vector<int> & arr){
    int n = arr.size();
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<n-1-i; j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

int main(){
    vector<int> arr ;
    arr.push_back(12);
    arr.push_back(23);
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(30);
    arr.push_back(50);
    int n = arr.size();
    bubble_sort(arr);
    for(int i = 0; i<n; i++){
        cout<< arr[i] << endl;
    }
    return 0;
}
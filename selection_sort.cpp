#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(vector<int> & arr){
    int n = arr.size();
    for(int i = 0; i<n-1; i++){
        int min_idx = i;
        for(int j = i+1; j<n;j++){
            if(arr[j]<arr[min_idx]){
                min_idx = j;
            }
        }
        swap(&arr[min_idx],&arr[i]);
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
    selection_sort(arr);
    for(int i = 0; i<n; i++){
        cout<< arr[i] << endl;
    }
    return 0;
}
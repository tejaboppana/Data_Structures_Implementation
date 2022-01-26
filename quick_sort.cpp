#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(vector<int> &arr, int left, int right){
    int pivot = arr[right];
    int i = left ;
    for(int j = left; j<=right-1; j++){
        if(arr[j] < pivot){
            swap(&arr[i],&arr[j]);
            i++;
        }
    }
    swap(&arr[i],&arr[right]);
    return i;
}

void quick_sort(vector<int> & arr,int left,int right){
    if(left < right){
        int pi = partition(arr,left,right);
        quick_sort(arr,left,pi-1);
        quick_sort(arr,pi+1,right);
    }
}

int main(){
    vector<int> arr ;
    arr.push_back(122);
    arr.push_back(23);
    arr.push_back(1);
    arr.push_back(51);
    arr.push_back(30);
    arr.push_back(50);
    arr.push_back(43);
    arr.push_back(200);
    arr.push_back(111);
    int n = arr.size();
    quick_sort(arr,0,n-1);
    for(int i = 0; i<n; i++){
        cout<< arr[i] << endl;
    }
    return 0;
}

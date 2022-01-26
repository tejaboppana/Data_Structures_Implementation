#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge(vector<int> & arr,int left,int right, int mid){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> left_array(n1);
    vector<int> right_array(n2);
    int left_index = left;
    for(int i = 0; i<n1; i++){
        left_array[i] = arr[left_index];
        left_index++;
    }
    int right_index = mid+1;
    for(int i = 0; i<n2; i++){
        right_array[i] = arr[right_index];
        right_index++;
    }
    left_index = 0; 
    right_index = 0;
    int main_index = left;
    while(left_index < n1 && right_index < n2){
        if(left_array[left_index]<= right_array[right_index]){
            arr[main_index] = left_array[left_index];
            left_index ++;
        }
        else{
            arr[main_index] = right_array[right_index];
            right_index++;
        }
        main_index++;
    }
    while(left_index < n1){
        arr[main_index] = left_array[left_index];
        left_index++;
        main_index++;
    }
    while(right_index < n2){
        arr[main_index] = right_array[right_index];
        main_index++;
        right_index++;
    }
}

void merge_sort(vector<int> & arr, int left, int right){
    if(left < right){
        int mid = left + (right-left)/2;
        merge_sort(arr,left,mid);
        merge_sort(arr,mid+1,right);
        merge(arr,left,right,mid);
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
    merge_sort(arr,0,n-1);
    for(int i = 0; i<n; i++){
        cout<< arr[i] << endl;
    }
    return 0;
}
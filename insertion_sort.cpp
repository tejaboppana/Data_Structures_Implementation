#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &arr){
    int n = arr.size();
    for(int i = 1; i<n; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]= arr[j];
            j = j-1;
        }
        arr[j+1] = key;
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
    insertion_sort(arr);
    for(int i = 0; i<n; i++){
        cout<< arr[i] << endl;
    }
    return 0;
}
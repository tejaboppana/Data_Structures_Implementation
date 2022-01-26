#include <bits/stdc++.h>
using namespace std;

bool binary_search(vector<int> arr, int x, int left, int right){
    int mid = left + (right-left)/2;
    if(left > right){
        return -1;
    }
    if(arr[mid]== x){
        return true;
    }
    else if (x > arr[mid]){
        return binary_search(arr,x,mid+1,right);
    }
    else{
        return binary_search(arr,x,left,mid-1);
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
    sort(arr.begin(),arr.end());
    if(binary_search(arr,1,0,n-1)){
        cout<< "The given number exists" ;
    }
    else
        cout <<"The given number does not exist";
    return 0;
}
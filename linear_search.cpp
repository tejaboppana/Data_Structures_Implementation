#include <stdio.h>
#include<vector>
#include<iostream> 

using namespace std;
bool linear_search(vector<int> arr, int x){
    for(int i = 0; i<arr.size(); i++){
        if(arr[i]==x)
            return true;
    }
    return false;
}

int main(){
    vector<int> arr ;
    arr.push_back(12);
    arr.push_back(23);
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(30);
    arr.push_back(50);
    if(linear_search(arr,23)){
        cout<< "The given number exists" ;
    }
    else
        cout <<"The given number does not exist";
    return 0;
}
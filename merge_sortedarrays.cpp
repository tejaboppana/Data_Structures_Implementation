#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& a, vector<int>& b){
    int n1 = a.size();
    int n2 = b.size();

    a.resize(n1+n2,0);

    int i = n1-1;
    int j = n2-1;
    int k = n1+n2-1;
    while(k>=0){
        if((i>=0 && a[i] > b[j]) || j < 0){
            a[k--] = a[i--];
        }
        else{
            a[k--] = b[j--];
        }
    }

}

int main(){
    int myints[] = {1,5,6,7,8};
    int n1 = sizeof(myints)/sizeof(myints[0]);
    vector<int> arr1(myints,myints+n1);

    int myints2 [] = {2,3,4,9,10,11};

    int n2 = sizeof(myints2)/sizeof(myints2[0]);
    vector<int> arr2(myints2,myints2+n2);


    merge(arr1,arr2);
    for(int i = 0; i<arr1.size(); i++){
        cout << arr1[i] << " " ;
    }
    cout << endl;
}
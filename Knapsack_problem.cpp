#include <bits/stdc++.h>
using namespace std;

int max(int a, int b){
    return (a>b)? a : b;
}

int knapsack_calculation(int wt [], int val [], int W, int n){
    vector<vector<int> > knapsack(n+1,vector<int>(W+1));
    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<W+1; j++){
            if(i==0 || j==0){
                knapsack[i][j]=0;
            }
            else if(wt[i-1]<=j){
                knapsack[i][j] = max(val[i-1]+knapsack[i-1][j-wt[i-1]],knapsack[i-1][j]);
            }
            else{
                knapsack[i][j] = knapsack[i-1][j];
            }
        }
    }
    return knapsack[n][W];
}

int main(){
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapsack_calculation(wt, val, W, n);
    return 0;
}
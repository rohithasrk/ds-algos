#include <bits/stdc++.h>
using namespace std;

void printArr(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int minCoins(int coins[], int n, int v){
    int dp[v+1];
    for(int i=0; i<=v; i++){
        dp[i] = INT_MAX;
    }
    dp[0] = 1;
    for(int i=1; i<=v; i++){
        for(int j=0; j<n; j++){
            if(coins[j]<=i){
                dp[i] = min(dp[i], 1+dp[i-coins[j]]);
            }
        }
    }
    return dp[v];
}

int main(){
    int coins[] = {9, 6, 5, 1};
    int n = sizeof(coins)/sizeof(coins[0]);
    cout<<minCoins(coins, n, 6)<<endl;
    cout<<minCoins(coins, n, 11)<<endl;
    cout<<minCoins(coins, n, 15)<<endl;
}

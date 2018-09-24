#include <bits/stdc++.h>
using namespace std;

// Find if a subset can be partitioned into two subsets
// of same sum

bool isPossible(int arr[], int n){
    int sum = 0;
    for(int i=0; i<n; i++) sum+=arr[i];
    if(sum%2) return false;

    // Find if there exists a subset with weight sum/2
    // Max capacity of a knapsack of capacity sum/2 should be sum/2
    int W = sum/2;
    int dp[n+1][W+1];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=W; j++){
            if(i==0 || j==0) dp[i][j] = 0;
            else{
                if(j-arr[i-1]>=0) dp[i][j] = max(arr[i-1]+dp[i-1][j-arr[i-1]], dp[i-1][j]);
                else dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W]==W;
}

int main(){
    int arr[] = {3, 1, 5, 9, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<isPossible(arr, n)<<endl;
}

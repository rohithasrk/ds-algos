#include <bits/stdc++.h>
using namespace std;

int min3(int a, int b, int c){
    return min(a, min(b, c));
}

int minCostPath(vector<vector<int>> &arr, int m, int n){
    int dp[m+1][n+1];
    for(int i=0; i<=m; i++){
       for(int j=0; j<=n; j++){
           if(i==0 || j==0){
               if(i==0 && j==0) dp[i][j] = arr[i][j];
               else if(i==0) dp[i][j] = arr[i][j] + dp[i][j-1];
               else dp[i][j] = arr[i][j] + dp[i-1][j];
           }else{
               dp[i][j] = arr[i][j] + min3(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]);
           }
       }
    }
    return dp[m][n];
}

int main(){
    int cost[3][3] = {{1, 2, 3}, {4, 8, 2}, {1, 5, 3}};
    int m = sizeof(cost)/sizeof(cost[0]);
    int n = sizeof(cost[0])/sizeof(cost[0][0]);
    vector<vector<int>> arr(m, vector<int>(n, 0));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            arr[i][j] = cost[i][j];
        }
    }
    cout<<minCostPath(arr, 2, 2)<<endl;
}

#include <bits/stdc++.h>
using namespace std;

bool subsetSum(int arr[], int n, int S){
    int dp[n+1][S+1];
    memset(dp, INT_MIN, sizeof(dp));
    for(int i=0; i<=n; i++){
        for(int j=0; j<=S; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }else{
                if(j-arr[i-1]>=0) dp[i][j] = arr[i-1]+dp[i-1][j-arr[i-1]];
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
            }
        }
    }
    return dp[n][S]==S;
}

int main(){
    int set[] = {3, 34, 4, 12, 5, 2};
    int n = sizeof(set)/sizeof(set[0]);
    cout<<subsetSum(set, n, 2211)<<endl;
    cout<<subsetSum(set, n, 22)<<endl;
    cout<<subsetSum(set, n, 24)<<endl;
}

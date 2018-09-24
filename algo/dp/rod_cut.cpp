#include <bits/stdc++.h>
using namespace std;

int rodCut(int arr[], int n){
    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=n; i++){
        dp[i] = arr[i-1];
        for(int j=1; j<i; j++){
            dp[i] = max(dp[i], dp[j]+dp[i-j]);
        }
    }
    return dp[n];
}

int main(){
    int arr[] = {3, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<rodCut(arr, n)<<endl;
}

#include <bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n){
    vector<int> dp(n);
    dp[0] = 0;
    for(int i=1; i<n; i++){
        dp[i] = INT_MAX;
        for(int j=0; j<i; j++){
            if(j+arr[j]>=i && dp[j]!=INT_MAX) dp[i] = min(dp[i], 1+dp[j]);
        }
    }
    return dp[n-1];
}

int main(){
    int arr[] = {1, 3, 6, 1, 0, 9};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<minJumps(arr, size)<<endl;
}

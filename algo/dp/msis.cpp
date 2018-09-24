#include <bits/stdc++.h>
using namespace std;

int maxSumIS(int arr[], int n){
    vector<int> dp(n);
    dp[0] = arr[0];
    int max_val = dp[0];
    for(int i=1; i<n; i++){
        dp[i] = arr[i];
        for(int j=0; j<i; j++){
            if(arr[j]<arr[i]){
                dp[i] = max(dp[i], arr[i]+dp[j]);
            }
        }
        max_val = max(dp[i], max_val);
    }
    return max_val;
}

int main(){
    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxSumIS(arr, n)<<endl;
}

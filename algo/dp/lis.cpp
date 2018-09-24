#include <bits/stdc++.h>
using namespace std;


int lis(int arr[], int n){
    vector<int> dp(n, 1);
    int max_len = 1;
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[j]<arr[i]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        max_len = max(dp[i], max_len);
    }
    return max_len;
}

int main(){
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<lis(arr, n)<<endl;
}

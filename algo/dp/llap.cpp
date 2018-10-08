#include <bits/stdc++.h>
using namespace std;

int llap(int arr[], int n){
    if(n<3) return n;
    int dp[n][n];
    int llap = 2;
    unordered_map<int, int> umap;
    int max_index = 0;
    int max_num = INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i]>max_num){
            max_index = i;
            max_num = arr[i];
        }
    }
    for(int i=0; i<n; i++){
        dp[i][max_index] = 2;
    }
    for(int i=n-1; i>=0; i--){
        for(int j=n-1; j>i; j--){
            int num = 2*arr[j]-arr[i];
            dp[i][j] = 2;
            if(umap.find(num)!=umap.end()){
                dp[i][j] = 1+dp[j][umap[num]];
            }
            llap = max(llap, dp[i][j]);
        }
        umap[arr[i]] = i;
    }
    return llap;
}

int main(){
    int arr[] = {9, 4, 7, 2, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<llap(arr, n)<<endl;
}

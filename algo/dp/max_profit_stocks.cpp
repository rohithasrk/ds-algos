#include <bits/stdc++.h>
using namespace std;

int maxProfit(int arr[], int n){
    int profit[n];
    memset(profit, 0, sizeof(profit));
    int max_price = arr[n-1];
    for(int i=n-2; i>=0; i--){
        max_price = max(max_price, arr[i]);

        profit[i] = max(profit[i+1], max_price-arr[i]);
    }

    int min_price = arr[0];

    for(int i=1; i<n; i++){
        min_price = min(arr[i], min_price);

        profit[i] = max(profit[i-1], profit[i]+arr[i]-min_price);
    }
    return profit[n-1];
}

int main(){
    int arr[] = {2, 30, 15, 10, 8, 25, 80};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxProfit(arr, n)<<endl;
}

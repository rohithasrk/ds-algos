#include <bits/stdc++.h>
using namespace std;

int LSCS(int arr[], int n){
    int max_ending_here = 0, max_sum = INT_MIN;
    for(int i=0; i<n; i++){
        max_ending_here+=arr[i];
        if(max_sum<max_ending_here) max_sum = max_ending_here;
        if(max_ending_here<0) max_ending_here = 0;
    }
    return max_sum;
}

int main(){
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<LSCS(arr, size)<<endl;
}

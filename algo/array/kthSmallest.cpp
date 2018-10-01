#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int r){
    int x = arr[r], i = l;
    for(int j=l; j<r; j++){
        if(arr[j]<=x) swap(arr[i++], arr[j]);
    }
    swap(arr[i], arr[r]);
    return i;
}

int randomPartition(int arr[], int l, int r){
    int n = r-l+1;
    int piv = rand() % n;
    swap(arr[l+piv], arr[r]);
    return partition(arr, l, r);
}

// Kth smallest element
int kthSmallest(int arr[], int l, int r, int k){
    if(k>0 && k<=r-l+1){
        int pos = randomPartition(arr, l, r);

        if(pos-l==k-1) return arr[pos];
        if(pos-l>k-1) return kthSmallest(arr, l, pos-1, k);
        return kthSmallest(arr, pos+1, r, k-pos+l-1);
    }
    return INT_MAX;
}

int main(){
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<kthSmallest(arr, 0, n-1, 1)<<endl;
    cout<<kthSmallest(arr, 0, n-1, 2)<<endl;
    cout<<kthSmallest(arr, 0, n-1, 3)<<endl;
    cout<<kthSmallest(arr, 0, n-1, 4)<<endl;
    cout<<kthSmallest(arr, 0, n-1, 5)<<endl;
}

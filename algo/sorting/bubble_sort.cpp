#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n){
    for(int k=0; k<n; k++){
        for(int i=0; i<n-k-1; i++){
            if(arr[i]>arr[i+1]) swap(arr[i], arr[i+1]);
        }
    }
}

void printArr(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {10, 4, 1, 2, 6, 3, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printArr(arr, n);
}

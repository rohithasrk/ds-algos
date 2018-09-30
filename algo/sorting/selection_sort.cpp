#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i=0; i<n; i++){
        int min_ind = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[min_ind]) min_ind = j;
        }
        swap(arr[i], arr[min_ind]);
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
    selectionSort(arr, n);
    printArr(arr, n);
}

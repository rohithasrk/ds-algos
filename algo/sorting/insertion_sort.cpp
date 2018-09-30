#include <iostream>
using namespace std;

void printArr(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int val = arr[i];
        int j = i;
        while(j>0 && arr[j-1]>val){
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = val;
    }
}

int main(){
    int arr[] = {10, 4, 1, 5, 3, 6, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, n);
    printArr(arr, n);
}

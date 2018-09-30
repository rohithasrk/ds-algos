#include <iostream>
using namespace std;

void printArr(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void merge(int arr[], int s1, int e1, int s2, int e2){
    int n = e2-s1+1;
    int temp[n];
    int i1=s1, i2=s2, i=0;
    while(i1<=e1 && i2<=e2){
        if(arr[i1]<arr[i2]) temp[i++] = arr[i1++];
        else temp[i++] = arr[i2++];
    }
    while(i1<=e1) temp[i++] = arr[i1++];
    while(i2<=e2) temp[i++] = arr[i2++];
    i1 = s1, i2 = s2, i=0;
    while(i1<=e1) arr[i1++] = temp[i++];
    while(i2<=e2) arr[i2++] = temp[i++];
}

void mergeSort(int arr[], int start, int end){
    if(start>=end) return;
    int mid = (start+end)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, mid, mid+1, end);
}

int main(){
    int arr[] = {10, 4, 1, 5, 3, 6, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0, n-1);
    printArr(arr, n);
}

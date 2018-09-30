#include <iostream>
using namespace std;

void printArr(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int partition(int arr[], int start, int end){
    int i = start + 1;
    int piv = arr[start];
    for(int j=start+1; j<=end; j++){
        if(arr[j]<piv) swap(arr[i++], arr[j]);
    }
    swap(arr[start], arr[i-1]);
    return i-1;
}

void quickSort(int arr[], int start, int end){
    if(start>=end) return;
    int piv = partition(arr, start, end);
    quickSort(arr, start, piv-1);
    quickSort(arr, piv+1, end);
}

int main(){
    int arr[] = {10, 4, 1, 5, 3, 6, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    printArr(arr, n);
}

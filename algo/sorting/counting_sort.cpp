#include <bits/stdc++.h>
using namespace std;

int getMax(int arr[], int n){
    int max_ele = arr[0];
    for(int i=1; i<n; i++){
        max_ele = max(max_ele, arr[i]);
    }
    return max_ele;
}

void countingSort(int arr[], int n){
    int max_ele = getMax(arr, n);
    int freq[max_ele+1];
    memset(freq, 0, sizeof(freq));
    for(int i=0; i<n; i++){
        freq[arr[i]]++;
    }
    for(int itr=0, i=0; i<n && itr<=max_ele; itr++){
        while(i<n && freq[itr]>0){
            arr[i++] = itr;
            freq[itr]--;
        }
    }
}

void printArr(int arr[], int n){
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    int arr[] = {10, 4, 1, 5, 3, 6, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    countingSort(arr, n);
    printArr(arr, n);
}

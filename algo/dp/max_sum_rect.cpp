#include <bits/stdc++.h>
using namespace std;
#define R 4
#define C 5

int maxSumRect(int arr[R][C]){
    for(int i=0; i<R; i++){
        for(int j=1; j<C; j++){
            arr[i][j]+=arr[i][j-1];
        }
    }

    int maxSum = INT_MIN, sum;
    for(int l=1; l<=C; l++){
        for(int j=0; j<C-l+1; j++){
            sum = 0;
            int j2 = j+l-1;
            for(int i=0; i<R; i++){
                int rowSum = arr[i][j2];
                if(j>0) rowSum -= arr[i][j-1];
                sum+= rowSum;
                maxSum = max(sum, maxSum);
                if(sum<0) sum=0;
            }
        }
    }
    return maxSum;
}

int main(){
    int arr[R][C] = {{1, 2, -1, -4, -20}, 
                     {-8, -3, 4, 2, 1}, 
                     {3, 8, 10, 1, 3}, 
                     {-4, -1, 1, 7, -6}};
    cout<<maxSumRect(arr)<<endl;
}

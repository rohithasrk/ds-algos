#include <bits/stdc++.h>
using namespace std;
#define R 3
#define C 3

int dp[R][C];

void printArr(){
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isValid(int x, int y){
    return (x>=0 && x<R && y>=0 && y<C);
}

int dfs(char arr[R][C], int i, int j, char c){
    if(!isValid(i, j)) return 0;
    if(arr[i][j]!=c) return 0;
    if(dp[i][j]!=-1 && arr[i][j]==c) return dp[i][j];
    int max_len = 1;
    if(isValid(i-1, j-1) && arr[i-1][j-1]==c+1){
        max_len = max(max_len, 1+dfs(arr, i-1, j-1, c+1));
    }
    if(isValid(i-1, j) && arr[i-1][j]==c+1){
        max_len = max(max_len, 1+dfs(arr, i-1, j, c+1));
    }
    if(isValid(i-1, j+1) && arr[i-1][j+1]==c+1){
        max_len = max(max_len, 1+dfs(arr, i-1, j+1, c+1));
    }
    if(isValid(i, j-1) && arr[i][j-1]==c+1){
        max_len = max(max_len, 1+dfs(arr, i, j-1, c+1));
    }
    if(isValid(i, j+1) && arr[i][j+1]==c+1){
        max_len = max(max_len, 1+dfs(arr, i, j+1, c+1));
    }
    if(isValid(i+1, j-1) && arr[i+1][j-1]==c+1){
        max_len = max(max_len, 1+dfs(arr, i+1, j-1, c+1));
    }
    if(isValid(i+1, j) && arr[i+1][j]==c+1){
        max_len = max(max_len, 1+dfs(arr, i+1, j, c+1));
    }
    if(isValid(i+1, j+1) && arr[i+1][j+1]==c+1){
        max_len = max(max_len, 1+dfs(arr, i+1, j+1, c+1));
    }
    return dp[i][j]=max_len;
}

int maxPathLength(char arr[R][C], char c){
    int max_len = 0;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(arr[i][j]==c){
                max_len = max(max_len, dfs(arr, i, j, c));
            }
        }
    }
    return max_len;
}

int main(){
    char arr[R][C] = {{'a','c', 'd'},
                   	  {'h', 'b', 'e'},
                      {'i', 'g', 'f'}};
    memset(dp, -1, sizeof(dp));
	cout<<maxPathLength(arr, 'e')<<endl;
	cout<<maxPathLength(arr, 'b')<<endl;
}

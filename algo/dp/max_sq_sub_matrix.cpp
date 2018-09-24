#include <bits/stdc++.h>
using namespace std;
#define R 6
#define C 5

int min3(int a, int b, int c){
    return min(a, min(b, c));
}

int maxSquare(int arr[R][C]){
    vector<vector<int>> dp(R, vector<int>(C));
    int max_side = 0;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(arr[i][j]){
                if(i>0 && j>0){
                    dp[i][j] = 1 + min3(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]);
                }else{
                    dp[i][j] = 1;
                }
            }else{
                dp[i][j] = 0;
            }
            max_side = max(max_side, dp[i][j]);
        }
    }
    return max_side;
}

int main(){
    int arr[R][C] = {{0, 1, 1, 0, 1},  
                   {1, 1, 0, 1, 0},  
                   {0, 1, 1, 1, 0}, 
                   {1, 1, 1, 1, 0}, 
                   {1, 1, 1, 1, 1}, 
                   {0, 0, 0, 0, 0}};
	cout<<maxSquare(arr)<<endl;
}

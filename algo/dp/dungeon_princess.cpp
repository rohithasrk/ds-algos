#include <bits/stdc++.h>
using namespace std;
#define R 3
#define C 3

int minPoints(int arr[R][C]){
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            arr[i][j] = -1*arr[i][j];
        }
    }
    int dp[R][C];
    dp[R-1][C-1] = max(1, arr[R-1][C-1]+1);
    for(int j=C-2; j>=0; j--){
        dp[R-1][j] = max(1, arr[R-1][j] + dp[R-1][j+1]);
    }
    for(int i=R-2; i>=0; i--){
        dp[i][C-1] = max(1, arr[i][C-1] + dp[i+1][C-1]);
    }
    for(int i=R-2; i>=0; i--){
        for(int j=C-2; j>=0; j--){
            dp[i][j] = max(1, arr[i][j] + min(dp[i+1][j], dp[i][j+1]));
        }
    }
    return dp[0][0];
}

int main(){
    int points[R][C] = {{-2,-3,3}, 
                        {-5,-10,1}, 
                        {10,30,-5}};
    cout<<minPoints(points)<<endl;
}

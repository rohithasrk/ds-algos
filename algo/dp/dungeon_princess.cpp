#include <bits/stdc++.h>
using namespace std;
#define R 3
#define C 3

int minPoints(int arr[R][C]){
    vector<vector<int>> dp(R+1, vector<int>(C+1, INT_MAX));
    dp[R][C-1] = 1;
    dp[R-1][C] = 1;
    for(int i=R-1; i>=0; i--){
        for(int j=C-1; j>=0; j--){
            int need = min(dp[i+1][j], dp[i][j+1]) - arr[i][j];
            dp[i][j] = need <=0 ? 1: need;
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

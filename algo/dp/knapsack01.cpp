#include <bits/stdc++.h>
using namespace std;

int maxVal(int val[], int wt[], int n, int w){
    int dp[n+1][w+1];
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<=n; i++){
        for(int j=0; j<=w; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
                continue;
            }

            int x = (j-wt[i-1]>=0) ? val[i-1]+dp[i-1][j-wt[i-1]]: 0;
            int y = (j>0)? dp[i-1][j]: 0;
            
            dp[i][j] = max(dp[i][j], max(x, y));
        }
    }
    return dp[n][w];
}

int main(){
    int val[] = {60, 100, 120}; 
    int wt[] = {10, 20, 30}; 
    int  W = 50; 
    int n = sizeof(val)/sizeof(val[0]);
    cout<<maxVal(val, wt, n, W)<<endl;
}

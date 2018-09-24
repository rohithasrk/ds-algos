#include <bits/stdc++.h>
using namespace std;


int nWays(int S[], int m, int n){
    int dp[n+1][m];

    for(int j=0; j<m; j++){
        dp[0][j] = 1;
    }

    for(int i=0; i<=n; i++){
        for(int j=0; j<m; j++){
            if(i==0 && j==0) continue;
            int x = (i-S[j]>=0)? dp[i-S[j]][j]: 0;
            int y = (j>0)? dp[i][j-1]: 0;

            dp[i][j] = x + y;
        }
    }
    return dp[n][m-1];
}

int nWaysOpt(int S[], int m, int n){
    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i=0; i<m; i++){
        for(int j=S[i]; j<=n; j++){
            dp[j] += dp[j-S[i]];
        }
    }
    return dp[n];
}

int main(){
    int coin[] = {1, 2, 3};
    int m = sizeof(coin)/sizeof(coin[0]);
    cout<<nWays(coin, m, 4)<<endl;
    cout<<nWaysOpt(coin, m, 5)<<endl;
    cout<<nWaysOpt(coin, m, 10)<<endl;
}

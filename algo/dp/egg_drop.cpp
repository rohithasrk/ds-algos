#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Min egg drops in worst case when
// there are n eggs and f floors
int minDrops(int n, int f){
    ll dp[n+1][f+1];
    for(int j=1; j<=f; j++){
        dp[1][j] = j;
    }
    for(int i=1; i<=n; i++){
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    for(int i=2; i<=n; i++){
        for(int j=2; j<=f; j++){
            dp[i][j] = INT_MAX;
            for(int k=1; k<=j; k++){
                ll q = 1 + max(dp[i-1][k-1], dp[i][j-k]);
                dp[i][j] = min(q, dp[i][j]);
            }
        }
    }
    return dp[n][f];
}

int main(){
    cout<<minDrops(2, 100)<<endl;
}

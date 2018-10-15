#include <bits/stdc++.h>
using namespace std;

int solve(int a[], int b[], int n, int x, int y){
    int dp[n+1][x+1][y+1];
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=n; i++){
        for(int j=0; j<=x; j++){
            for(int k=0; k<=y; k++){
                if(j==0 || k==0){
                    if(j==0 && k==0) dp[i][j][k] = 0;
                    else if(j==0){
                        dp[i][j][k] = max(dp[i-1][j][k],
                                        b[i-1]+dp[i-1][j][k-1]);
                    }else{
                        dp[i][j][k] = max(dp[i-1][j][k],
                                        a[i-1]+dp[i-1][j-1][k]);
                    }
                }else{
                    dp[i][j][k] = max(max(a[i-1]+dp[i-1][j-1][k],
                                  b[i-1]+dp[i-1][j][k-1]),
                                  dp[i-1][j][k]);
                }
            }
        }
    }
    return dp[n][x][y];
}

int main() {
	int t; cin>>t;
	while(t--){
	    int n, x, y; cin>>n>>x>>y;
	    int a[n], b[n];
	    for(int i=0; i<n; i++) cin>>a[i];
	    for(int i=0; i<n; i++) cin>>b[i];
	    cout<<solve(a, b, n, x, y)<<endl;
	}
	return 0;
}

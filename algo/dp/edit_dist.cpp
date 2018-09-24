#include <bits/stdc++.h>
using namespace std;

// Minimum edits required to convert A to B
// Using Insert, Remove or Delete operations
int editDist(string A, string B){
    int n = A.length();
    int m = B.length();
    int dp[n+1][m+1];
    memset(dp, sizeof(dp), 0);
    for(int i=0; i<=n; i++){
        dp[i][0] = i;
    }

    for(int j=0; j<=m; j++){
        dp[0][j] = j;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(A[i-1]==B[j-1]) dp[i][j] = dp[i-1][j-1];
            else{
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }
        }
    }
    return dp[n][m];
}

int main(){
    cout<<editDist("cat", "cut")<<endl;
    cout<<editDist("sunday", "saturday")<<endl;
    cout<<editDist("geek", "gesek")<<endl;
}

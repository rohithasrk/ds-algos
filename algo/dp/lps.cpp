#include <bits/stdc++.h>
using namespace std;

int lps(string A){
    int n = A.length();

    int dp[n][n];

    memset(dp, 0, sizeof(dp));

    for(int l=1; l<=n; l++){
        for(int i=0; i<n-l+1; i++){
            int j = i+l-1;
            if(l==1){
                dp[i][j] = 1;
            }
            else if(l==2){
                if(A[i]==A[j]) dp[i][j] = 2;
                else dp[i][j] = 1;
            }else{
                if(A[i]==A[j]){
                    dp[i][j] = 2+dp[i+1][j-1];
                }else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
    }
    return dp[0][n-1];
}

int main(){
    cout<<lps("bbabcbcab")<<endl;
    cout<<lps("bbbbb")<<endl;
    cout<<lps("bbacbb")<<endl;
}

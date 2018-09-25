#include <bits/stdc++.h>
using namespace std;

int N, S;

int countDigitSum(){
    int dp[N+1][S+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int n=1; n<=N; n++){
        for(int s=0; s<=S; s++){
            if(n==1){
                if(s>9) dp[n][s] = 0;
                else dp[n][s] = 1;
            }else{
                if(n!=N) dp[n][s] += dp[n-1][s];
                for(int d=1; d<10; d++){
                    if(s-d>=0) dp[n][s] += dp[n-1][s-d];
                }
            }
        }
    }
    return dp[N][S];
}

int main(){
   N = 3;
   S = 5;
   cout<<countDigitSum()<<endl;
}

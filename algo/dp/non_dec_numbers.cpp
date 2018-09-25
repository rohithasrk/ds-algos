#include <bits/stdc++.h>
using namespace std;

int numNonDec(int N){
    if(N==1) return 10;
    int dp[N][10];
    memset(dp, 0, sizeof(dp));

    // dp[n][i] represents number of non decreasing n digit numbers
    // with prev digit i
    for(int n=0; n<N; n++){
        for(int i=0; i<10; i++){
            if(n==0){
                // One digit case
                dp[n][i] = 1;
            }else{
                for(int j=0; j<=i; j++){
                    dp[n][i]+=dp[n-1][j];
                }
            }
        }
    }
    int num = 0;
    for(int i=0; i<10; i++){
        num += dp[N-1][i];
    }
    return num;
}

int main(){
    int N = 3;
    cout<<numNonDec(3)<<endl;
}

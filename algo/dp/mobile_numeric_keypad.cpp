#include <bits/stdc++.h>
using namespace std;
#define R 4
#define C 3

int xmov[] = {0, 1, -1, 0, 0};
int ymov[] = {0, 0, 0, 1, -1};
int nmov = 5;

int nWays(int N){
    int dp[N+1][R][C];
    memset(dp, 0, sizeof(dp));
    for(int n=1; n<=N; n++){
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(i!=3 || (i==3 && j==2)){
                    if(n==1){
                        dp[n][i][j] = 1;
                    }else{
                        int i_n, j_n;
                        for(int k=0; k<nmov; k++){
                            i_n = i + xmov[k];
                            j_n = j + ymov[k];
                            if(i_n>=0 && i_n<R && j_n>=0 && j_n<C){
                                dp[n][i][j]+=dp[n-1][i_n][j_n];
                            }
                        }
                    }
                }
            }
        }
    }
    int num = 0;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            num+=dp[N][i][j];
        }
    }
    return num;
}

int main(){
    int keypad[4][3] = {{'1', '2', '3'},
                        {'4', '5', '6'},
                        {'7', '8', '9'},
                        {'*', '0', '#'}};
    cout<<nWays(1)<<endl;
    cout<<nWays(2)<<endl;
    cout<<nWays(3)<<endl;
    cout<<nWays(4)<<endl;
    cout<<nWays(5)<<endl;
}

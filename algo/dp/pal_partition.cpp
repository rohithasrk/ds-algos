#include <bits/stdc++.h>
using namespace std;

int minPal(string S){
    int n = S.length();
    int C[n][n];
    int P[n][n];

    for(int i=0; i<n; i++){
        P[i][i] = 1;
        C[i][i] = 0;
    }

    for(int l=2; l<=n; l++){
        for(int i=0; i<n-l+1; i++){
            int j = i+l-1;
            if(l==2){
                if(S[i]==S[j]){
                    P[i][j] = 1;
                    C[i][j] = 0;
                }else{
                    C[i][j] = 1;
                    P[i][j] = 0;
                }
            }else if(S[i]==S[j] && P[i+1][j-1]==1){
                C[i][j] = 0;
                P[i][j] = 1;
            }else{
                C[i][j] = INT_MAX;
                for(int k=i; k<j; k++){
                    C[i][j] = min(C[i][j], C[i][k]+1+C[k+1][j]);
                }
            }
        }
    }
    return C[0][n-1];
}

int main(){
   cout<<minPal("ababbbabbababa")<<endl;
}

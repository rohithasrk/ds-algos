#include <bits/stdc++.h>
using namespace std;


int nWays(char symbols[], char operators[], int n){
    int dpT[n][n];
    int dpF[n][n];

    memset(dpT, 0, sizeof(dpT));
    memset(dpF, 0, sizeof(dpF));

    for(int i=0; i<n; i++){
        if(symbols[i]=='T') dpT[i][i] = 1;
        else dpF[i][i] = 1;
    }
    for(int l=2; l<=n; l++){
        for(int i=0; i<n-l+1; i++){
            int j = i+l-1, opi;
            for(int k=i; k<j; k++){
                opi = (2*k+1)/2;
                if(operators[opi]=='&'){
                    dpT[i][j] += dpT[i][k]*dpT[k+1][j];
                    dpF[i][j] += dpF[i][k]*dpT[k+1][j] +
                                 dpT[i][k]*dpF[k+1][j] +
                                 dpF[i][k]*dpF[k+1][j];
                }else if(operators[opi]=='^'){
                    dpT[i][j] += dpT[i][k]*dpF[k+1][j] +
                                 dpF[i][k]*dpT[k+1][j];
                    dpF[i][j] += dpT[i][k]*dpT[k+1][j] +
                                 dpF[i][k]*dpF[k+1][j];
                }else if(operators[opi]=='|'){
                    dpF[i][j] += dpF[i][k]*dpF[k+1][j];
                    dpT[i][j] += dpF[i][k]*dpT[k+1][j] +
                                 dpT[i][k]*dpF[k+1][j] +
                                 dpT[i][k]*dpT[k+1][j];
                }
            }
        }
    }
    return dpT[0][n-1];
}

int main(){
    char symbols[] = "TTFTT"; 
    char operators[] = "|&^|";
    int n = strlen(symbols);
    cout<<nWays(symbols, operators, n)<<endl;
}

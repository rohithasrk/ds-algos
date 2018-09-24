#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define F first
#define S second
typedef pair<int, int> pii;

pii longestPalSubs(string A){
    int max_len = 1;
    int start = 0;
    int n = A.length();
    bool dp[n][n];
    for(int i=0; i<n; i++){
        dp[i][i] = true;
    }
    for(int l=2; l<=n; l++){
        for(int i=0; i<n-l+1; i++){
            int j = i+l-1;
            if(l==2){
                if(A[i]==A[j]){
                    dp[i][j] = true;
                }else{
                    dp[i][j] = false;
                }
            }else{
                if(A[i]==A[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                }else{
                    dp[i][j] = false;
                }
            }
            if(dp[i][j]){
                if(max_len<l){
                    start = i;
                    max_len = l;
                }
            }
        }
    }
    return mp(start, max_len);
}

int main(){
    string s = "forgeeksskeegfor";
    pii x = longestPalSubs(s);
    cout<<s.substr(x.F, x.S)<<endl;
}

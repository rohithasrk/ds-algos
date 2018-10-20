/*
Given two numbers n and k, find s of lowercase alphabets such that the sum of values of all elements in equal to k
*/

#include <bits/stdc++.h>
using namespace std;
#define pb push_back

string solve(int n, int K){
    if(K>26*n) return "NOT POSSIBLE";
    bool dp[n+1][K+1];
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=K; j++){
            for(int k=1; k<=26 && k<=j; k++){
                dp[i][j] = dp[i][j] || dp[i-1][j-k];
            }
        }
    }
    if(!dp[n][K]) return "NOT POSSIBLE";
    string res = "";
    int i = n, j=K;
    while(i>0){
        for(int k=26; k>0; k--){
            if(j>=k && dp[i-1][j-k]){
                res.push_back('a'+k-1);
                j = j-k;
                break;
            }
        }
        i--;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    int n, k;
    cin>>n>>k;
    cout<<solve(n, k)<<endl;
}

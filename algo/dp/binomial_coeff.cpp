#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> dp;

ll C(int n, int r){
    if(r>n) return -1;
    if(r==n) return 1;
    if(n<dp.size()) return dp[n]/(dp[n-r]*dp[r]);
    if(dp.size()==0) dp.push_back(1);
    int s = dp.size();
    for(int i=s; i<=n; i++){
        s = dp.size();
        dp.push_back(i*dp[s-1]);
    }
    return dp[n]/(dp[n-r]*dp[r]);
}

// Using C(n, k) = C(n-1, k-1) + C(n-1, k)
ll nCr(int n, int r){
    if(r>n) return 0;
    ll table[n+1][r+1];
    memset(table, 0, sizeof(table));
    for(int i=1; i<=n; i++){
        for(int j=i; j<=r; j++){
            if(i==j) table[i][j] = 1;
            else table[i][j] = table[i-1][j-1] + table[i-1][j];
        }
    }
    return table[n][r];
}

int main(){
    cout<<C(3, 3)<<endl;
    cout<<C(10, 3)<<endl;
    cout<<C(20, 10)<<endl;
    cout<<C(20, 10)<<endl;
}

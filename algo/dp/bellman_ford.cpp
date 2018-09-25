#include <bits/stdc++.h>
using namespace std;
#define R 5
#define C 5
#define ll long long

void printVec(vector<ll> &vec){
    for(int i=0; i<vec.size(); i++){
            cout<<vec[i]<<" ";
    }
    cout<<endl;
}

vector<ll> shortestPath(vector<vector<ll>> &adj, int src){
    int n = adj.size();
    vector<ll> dp(n, INT_MAX);
    dp[src] = 0;
    for(int i=0; i<n; i++){
        if(i!=src){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    if(dp[j]!=INT_MAX){
                        dp[k] = min(dp[k], dp[j]+adj[j][k]);
                    }
                }
            }
        }
    }
    return dp;
}

int main(){
    int graph[R][C] = {{0, -1, 4, INT_MAX, INT_MAX},
                       {INT_MAX, 0, 3, 2, 2},
                       {INT_MAX, INT_MAX, 0, INT_MAX, INT_MAX},
                       {INT_MAX, 1, 5, 0, INT_MAX},
                       {INT_MAX, INT_MAX, INT_MAX, -3, 0}};
    vector<vector<ll>> adj(R, vector<ll>(C));
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            adj[i][j] = graph[i][j];
        }
    }
    vector<ll> sPaths = shortestPath(adj, 0);
    printVec(sPaths);
}

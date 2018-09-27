#include <bits/stdc++.h>
using namespace std;
#define V 4

bool isBipartite(int G[V][V], int src){
    int color[V];
    memset(color, -1, sizeof(color));
    color[src] = 1;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int u = q.front();
        q.pop();

        if(G[u][u]==1) return false;

        for(int v=0; v<V; v++){
            if(G[u][v] && color[v]==-1){
                color[v] = 1^color[u];
                q.push(v);
            }
            else if(G[u][v] && color[v]==color[u]) return false;
        }
    }
    return true;
}

int main(){
    int G[V][V] = {{0, 1, 0, 1},
                   {1, 0, 1, 0},
                   {0, 1, 0, 1},
                   {1, 0, 1, 0}};
    if(isBipartite(G, 0)) cout<<"The graph is bipartite"<<endl;
}

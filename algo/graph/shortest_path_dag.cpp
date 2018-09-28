#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define NINF INT_MIN
#define INF INT_MAX

typedef pair<int, int> pii;

// Adjacency list representation of a graph
// Unweighted graph
unordered_map<int, vector<pii>> graph;
map<int, int> dist;

void topologicalSortUtil(int u, stack<int> &st, set<int> &vis){
    vis.insert(u);

    int v;
    for(int i=0; i<graph[u].size(); i++){
        v = graph[u][i].F;
        if(vis.find(v)==vis.end()){
            topologicalSortUtil(v, st, vis);
        }
    }

    st.push(u);
}

void init_dist(){
    for(auto i=graph.begin(); i!=graph.end(); i++){
        dist[i->F] = INF;
    }
}

void shortDist(int src){
    dist.clear();
    stack<int> st;
    set<int> vis;
    for(auto i=graph.begin(); i!=graph.end(); i++){
        if(vis.find(i->F)==vis.end()){
            topologicalSortUtil(i->F, st, vis);
        }
    }
    init_dist();
    dist[src] = 0;

    int u, v, wt;
    while(!st.empty()){
        u = st.top();
        st.pop();
        if(dist[u]!=INF){
            for(int i=0; i<graph[u].size(); i++){
                v = graph[u][i].F;
                wt = graph[u][i].S;
                
                dist[v] = min(dist[v], dist[u]+wt);
            }
        }
    }
}

void printDist(){
    for(auto i=dist.begin(); i!=dist.end(); i++){
        cout<<i->F<<" "<<i->S<<endl;
    }
}

int main(){
    graph.clear();
    graph[0].pb(mp(1, 5));
    graph[0].pb(mp(2, 3));
    graph[1].pb(mp(2, 2));
    graph[1].pb(mp(3, 6));
    graph[2].pb(mp(3, 7));
    graph[2].pb(mp(4, 4));
    graph[2].pb(mp(5, 2));
    graph[3].pb(mp(4, -1));
    graph[3].pb(mp(5, 1));
    graph[4].pb(mp(5, -2));
    shortDist(1);
    printDist();
}

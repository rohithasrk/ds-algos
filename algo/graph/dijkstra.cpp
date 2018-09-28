#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define INF INT_MAX

typedef pair<ll, int> pii;
typedef unordered_map<int, ll> umap;
typedef unordered_map<int, vector<pii>> gmap;

gmap graph;
umap dist;

void init(){
    graph.clear();
}

void init_dist(){
    for(auto i=graph.begin(); i!=graph.end(); i++){
        dist[i->F] = INT_MAX;
    }
}

void addEdge(int u, int v, int w){
    graph[u].pb(mp(w, v));
    graph[v].pb(mp(w, u));
}

void dijkstra(int src){
    dist.clear();
    init_dist();
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    set<int> vis;
    pq.push(mp(0, src));
    pii p;
    int x, y;
    ll d;
    while(!pq.empty()){
        p = pq.top();
        pq.pop();
        x = p.S;
        if(vis.find(x)!=vis.end()) continue;
        d = p.F;
        dist[x] = min(dist[x], d);
        d = dist[x];
        vis.insert(x);
        for(int i=0; i<graph[x].size(); i++){
            y = graph[x][i].S;
            if(vis.find(y)==vis.end()){
                pq.push(mp(d+graph[x][i].F, y));
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
    init();
    addEdge(0, 1, 4);
    addEdge(0, 7, 8);
    addEdge(1, 7, 11);
    addEdge(1, 2, 8);
    addEdge(7, 8, 7);
    addEdge(2, 8, 2);
    addEdge(7, 6, 1);
    addEdge(8, 6, 6);
    addEdge(2, 3, 7);
    addEdge(2, 5, 4);
    addEdge(6, 5, 2);
    addEdge(3, 5, 14);
    addEdge(3, 4, 9);
    addEdge(5, 4, 10);
    dijkstra(0);
    printDist();
}

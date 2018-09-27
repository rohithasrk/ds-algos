#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define F first
#define S second
#define NIL -1

typedef unordered_map<int, vector<int>> gmap;
typedef unordered_map<int, int> umap;

gmap graph;
umap vis;
umap disc;
umap low;
umap parent;
umap ap;

void addEdge(int u, int v){
    graph[u].pb(v);
    graph[v].pb(u);
}

void APUtil(int u){
    static int time = 0;

    int children = 0;

    vis[u] = 1;

    disc[u] = low[u] = ++time;

    for(int i=0; i<graph[u].size(); i++){
        int v = graph[u][i];

        if(!vis[v]){
            children++;
            parent[v] = u;
            APUtil(v);

            low[u] = min(low[u], low[v]);

            if(parent[u]==NIL && children>1){
                ap[u] = 1;
            }

            if(parent[u]!=NIL && low[v]>=disc[u]){
                ap[u] = 1;
            }
        }
        else if(v!=parent[u]) low[u] = min(low[u], disc[v]);
    }
}

void AP(){
    vis.clear();
    disc.clear();
    low.clear();
    parent.clear();
    ap.clear();

    for(auto i=graph.begin(); i!=graph.end(); i++){
        parent[i->F] = NIL;
        vis[i->F] = 0;
        ap[i->F] = 0;
    }

    for(auto i=graph.begin(); i!=graph.end(); i++){
        if(vis.find(i->F)!=vis.end()){
            APUtil(i->F);
        }
    }

    for(auto i=ap.begin(); i!=ap.end(); i++){
        if(i->S==1) cout<<i->F<<" ";
    }
    cout<<endl;
}

int main(){
    graph.clear();
    addEdge(1, 0);
    addEdge(0, 2);
    addEdge(2, 1);
    addEdge(0, 3);
    addEdge(3, 4);

    cout<<"Articulation points: ";
    AP();

    graph.clear();
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 3);

    cout<<"Articulation points: ";
    AP();

	graph.clear();
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 0);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(1, 6);
    addEdge(3, 5);
    addEdge(4, 5);
    cout<<"Articulation points: ";
    AP();     
}

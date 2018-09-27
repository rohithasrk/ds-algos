#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define F first
#define S second

typedef unordered_map<int, int> umap;
typedef unordered_map<int, vector<int>> gmap;

gmap graph;

void init(){
    graph.clear();
}

void addEdge(int u, int w){
    graph[u].pb(w);
    graph[w].pb(u);
}

bool isCyclicUtil(int v, umap &vis, int parent){
    vis[v] = 1;

    int id;
    for(int i=0; i<graph[v].size(); i++){
        id = graph[v][i];
        if(!vis[id]){
            if(isCyclicUtil(id, vis, v)) return true;
        }
        else if(id!=parent) return true;
    }
    return false;
}

bool isCyclic(){
    umap vis;
    for(auto i=graph.begin(); i!=graph.end(); i++){
        vis[i->F] = 0;
    }
    if(isCyclicUtil(graph.begin()->F, vis, -1)) return true;
	else return false;
}

void dfs(umap &vis, int node){
    int id;
    for(int i=0; i<graph[node].size(); i++){
        id = graph[node][i];
        if(!vis[id]){
            vis[id] = 1;
            dfs(vis, id);
        }
    }
}

bool isConnected(){
    umap vis;
    for(auto i=graph.begin(); i!=graph.end(); i++){
        vis[i->F] = 0;
    }
    dfs(vis, graph.begin()->F);
    for(auto i=vis.begin(); i!=vis.end(); i++){
        if(i->S==0) return false;
    }
    return true;
}

bool isTree(){
    return (isConnected() && !isCyclic());
}

int main(){
    init();
    addEdge(1, 0);
    addEdge(0, 2);
    addEdge(0, 3);
    addEdge(3, 4);
    cout<<isTree()<<endl;

    init();
	addEdge(1, 0);
    addEdge(0, 2);
    addEdge(2, 1);
    addEdge(0, 3);
    addEdge(3, 4);
	cout<<isTree()<<endl;
}

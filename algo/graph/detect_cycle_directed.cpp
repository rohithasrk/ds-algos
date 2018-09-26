#include <bits/stdc++.h>
using namespace std;
#define pb push_back

// Adjacency list representation of a graph
// Unweighted graph
unordered_map<int, vector<int>> graph;
set<int> vis;

bool dfs(int node, set<int> rec){
    if(rec.find(node)!=rec.end()) return true;
    rec.insert(node);

    for(int i=0; i<graph[node].size(); i++){
        if(vis.find(graph[node][i])==vis.end()){
            vis.insert(graph[node][i]);
            if(dfs(graph[node][i], rec)) return true;
        }
        else if(rec.find(graph[node][i])!=rec.end()) return true;
    }
    return false;
}

bool isCyclic(){
    set<int> rec;
    for(auto i=graph.begin(); i!=graph.end(); i++){
        int node = i->first;
        if(vis.find(node)==vis.end()){
            vis.insert(node);
            if(dfs(node, rec)) return true;
        }
    }
    return false;
}

int main(){
    graph.clear();
    vis.clear();
    graph[0].pb(1);
    graph[0].pb(2);
    graph[1].pb(2);
    graph[2].pb(0);
    graph[2].pb(3);
    graph[3].pb(3);
    if(isCyclic()) cout<<"Graph contains a cycle"<<endl;
    else cout<<"Graph is acyclic"<<endl;
}

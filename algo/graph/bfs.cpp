#include <bits/stdc++.h>
using namespace std;
#define pb push_back

// Adjacency list representation of a graph
// Unweighted graph
unordered_map<int, vector<int>> graph;
set<int> vis;

void bfs(int node){
    vis.clear();
    queue<int> q;
    q.push(node);
    vis.insert(node);
    while(!q.empty()){
        node = q.front();
        cout<<node<<" ";
        q.pop();
        for(int i=0; i<graph[node].size(); i++){
            if(vis.find(graph[node][i])==vis.end()){
                vis.insert(graph[node][i]);
                q.push(graph[node][i]);
            }
        }
    }
    cout<<endl;
}

int main(){
    graph.clear();
    graph[0].pb(1);
    graph[0].pb(2);
    graph[1].pb(2);
    graph[2].pb(0);
    graph[2].pb(3);
    graph[3].pb(3);
    cout<<"BFS: ";
    bfs(2);
}

#include <bits/stdc++.h>
using namespace std;
#define pb push_back

// Adjacency list representation of a graph
// Unweighted graph
unordered_map<int, vector<int>> graph;

void tSortUtils(int node, set<int> &vis, stack<int> &res){
    vis.insert(node);

    for(int i=0; i<graph[node].size(); i++){
        if(vis.find(graph[node][i])==vis.end()){
            tSortUtils(graph[node][i], vis, res);
        }
    }
    res.push(node);
}

void tSort(){
    stack<int> result;
    set<int> vis;
    for(auto i=graph.begin(); i!=graph.end(); i++){
        int node = i->first;
        if(vis.find(node)==vis.end()){
            tSortUtils(node, vis, result);
        }
    }
    while(!result.empty()){
        cout<<result.top()<<" ";
        result.pop();
    }
    cout<<endl;
}

int main(){
    graph.clear();
    graph[2].pb(3);
    graph[3].pb(1);
    graph[5].pb(0);
    graph[5].pb(2);
    graph[4].pb(0);
    graph[4].pb(1);
    cout<<"Topological order: ";
    tSort();
}

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef pair<int, int> pii;

// Adjacency list representation of a graph
// Unweighted graph
unordered_map<int, vector<int>> graph;
unordered_map<int, int> parent;
set<pii> vis;

int find(int node){
    if(parent[node]==node) return node;
    return find(parent[node]);
}

void Union(int x, int y){
    int xp = find(x);
    int yp = find(y);
    parent[xp] = yp;
}

void swap(int &i, int &j){
    if(i>j){
        int tmp;
        tmp = i;
        i = j;
        j = tmp;
    }
}

bool isCyclic(){
    // Initialising the parent map
    vis.clear();
    for(auto i=graph.begin(); i!=graph.end(); i++){
        parent[i->first] = i->first;
    }

    for(auto i=graph.begin(); i!=graph.end(); i++){
        for(int j=0; j<graph[i->first].size(); j++){
            int src = i->first;
            int dest = graph[i->first][j];
            swap(src, dest);
            pii pr = mp(src, dest);
            if(vis.find(pr)==vis.end()){
                vis.insert(pr);
                int x = find(src);
                int y = find(dest);

                if(x==y) return true;

                Union(x, y);
            }
        }
    }
    return false;
}

int main(){
    graph.clear();
    parent.clear();
    graph[0].pb(1);
    graph[0].pb(2);
    graph[1].pb(0);
    graph[2].pb(0);
    graph[1].pb(2);
    graph[2].pb(1);
    graph[2].pb(3);
    graph[3].pb(2);
    graph[3].pb(3);
    if(isCyclic()) cout<<"Graph contains a cycle"<<endl;
    else cout<<"Graph is acyclic"<<endl;
}

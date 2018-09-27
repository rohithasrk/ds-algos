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
unordered_map<int, int> dist;

void distUtils(int node, int d){
    dist[node] = max(d, dist[node]);

    for(int i=0; i<graph[node].size(); i++){
        distUtils(graph[node][i].F, graph[node][i].S+d);
    }
}

void maxDist(int src){
    dist.clear();
    for(auto i=graph.begin(); i!=graph.end(); i++){
        if(i->F==src) dist[i->F] = 0;
        else dist[i->F] = NINF;
    }
    for(int i=0; i<graph[src].size(); i++){
        distUtils(graph[src][i].F, graph[src][i].S);
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
    maxDist(1);
    printDist();
}

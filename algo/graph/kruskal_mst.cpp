#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef pair<int, int> pii;
typedef unordered_map<int, int> umap;

vector<pair<ll, pii>> weights;
umap parent;
int nodes, edges;

void initialize(){
    weights.clear();
    parent.clear();
    for(int i=0; i<nodes; i++){
        parent[i] = i;
    }
}

void addEdge(int x, int y, ll z){
    weights.pb(mp(z, mp(x, y)));
}

int find(int node){
    while(parent[node]!=node){
        parent[node] = find(parent[node]);
        node = parent[node];
    }
    return node;
}

int Union(int x, int y){
    int xs = find(x);
    int ys = find(y);
    parent[xs] = ys;
}

ll kruskal(){
    sort(weights.begin(), weights.end());
    ll cost, minCost = 0;
    int x, y;
    for(int i=0; i<weights.size(); i++){
        x = weights[i].S.F;
        y = weights[i].S.S;
        cost = weights[i].F;

        if(find(x)!=find(y)){
            minCost+=cost;
            Union(x, y);
        }
    }
    return minCost;
}

int main(){
    int x, y;
    ll weight, cost, minCost;
    nodes = 9;
    initialize();
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
    minCost = kruskal();
    cout<<minCost<<endl;
}

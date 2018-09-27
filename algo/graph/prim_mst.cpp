#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef pair<ll, int> pli;
set<int> marked;
unordered_map<int, vector<pli>> adj;

void init(){
    adj.clear();
    marked.clear();
}

void addEdge(int u, int v, ll w){
    adj[u].pb(mp(w, v));
    adj[v].pb(mp(w, u));
}

bool ismarked(int x){
    return (marked.find(x)!=marked.end());
}

void mark(int x){
    marked.insert(x);
}

ll prim(int x){
    ll minCost = 0;
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    int y;
    pli p;
    pq.push(mp(0, x));
    while(!pq.empty()){
        p = pq.top();
        pq.pop();
        x = p.S;
        if(ismarked(x)) continue;
        minCost+=p.F;
        mark(x);
        for(int i=0; i<adj[x].size(); i++){
            y = adj[x][i].S;
            if(!ismarked(y)) pq.push(adj[x][i]);
        }
    }
    return minCost;
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
    ll minCost = prim(1);
    cout<<minCost<<endl;
}

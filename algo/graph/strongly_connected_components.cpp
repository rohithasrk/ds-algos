#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back

typedef unordered_map<int, vector<int>> gmap;

gmap graph;
gmap rev;
vector<vector<int>> res;

void init(){
    graph.clear();
    res.clear();
    rev.clear();
}

void addEdge(int u, int v){
    graph[u].pb(v);
}

void reverseEdges(){
    int u, v;
    for(auto i=graph.begin(); i!=graph.end(); i++){
        u = i->F;
        for(int j=0; j<i->S.size(); j++){
            v = i->S[j];
            rev[v].pb(u);
        }
    }
}

void DFS(int u, set<int> &vis, stack<int> &st){
    vis.insert(u);

    int v;
    for(int i=0; i<graph[u].size(); i++){
        v = graph[u][i];
        if(vis.find(v)==vis.end()){
            DFS(v, vis, st);
        }
    }
    st.push(u);
}

void SCUtils(int u, vector<int> &comp, set<int> &vis){
    vis.insert(u);
    comp.pb(u);

    int v;
    for(int i=0; i<rev[u].size(); i++){
        v = rev[u][i];
        if(vis.find(v)==vis.end()){
            SCUtils(v, comp, vis);
        }
    }
}

void printSt(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
}

void printVec(vector<int> vec){
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

void get_strongly_connected(){
    stack<int> st;
    set<int> vis;

    int u;
    for(auto i=graph.begin(); i!=graph.end(); i++){
        u = i->F;
        if(vis.find(u)==vis.end()){
            DFS(u, vis, st);
        }
    }

    reverseEdges();
    vis.clear();
    vector<int> comp;
    while(!st.empty()){
        u = st.top();
        st.pop();
        if(vis.find(u)==vis.end()){
            SCUtils(u, comp, vis);
        }
        if(comp.size()>0){
            res.pb(comp);
            comp.clear();
        }
    }
}

void printComp(){
    for(int i=0; i<res.size(); i++){
        cout<<"Component "<<i+1<<": ";
        for(int j=0; j<res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    init();
    addEdge(1, 0);
    addEdge(0, 2);
    addEdge(2, 1);
    addEdge(0, 3);
    addEdge(3, 4);
    get_strongly_connected();
    printComp();
}

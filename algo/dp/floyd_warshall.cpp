#include <bits/stdc++.h>
using namespace std;

void printVec(vector<vector<int>> &graph){
    int n = graph.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

vector<vector<int>> shortestDistMat(vector<vector<int>> &graph){
    int n = graph.size();
    vector<vector<int>> res = graph;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(res[i][k]!=INT_MAX && res[k][j]!=INT_MAX){
                    res[i][j] = min(res[i][j], res[i][k]+res[k][j]);
                }
            }
        }
    }
    return res;
}

int main(){
	int graph[4][4] = { {0,   5,  INT_MAX, 10}, 
					{INT_MAX, 0,   3, INT_MAX}, 
					{INT_MAX, INT_MAX, 0,   1}, 
					{INT_MAX, INT_MAX, INT_MAX, 0} 
				  };
    vector<vector<int>> adj(4, vector<int>(4));
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            adj[i][j] = graph[i][j];
        }
    }
    adj = shortestDistMat(adj);
    printVec(adj);
}

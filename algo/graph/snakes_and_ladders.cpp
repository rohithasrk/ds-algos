#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef pair<int, int> pii;

int minDiceThrows(int moves[], int N){
    queue<pii> q;
    int visited[N];
    memset(visited, 0, sizeof(visited));
    visited[0] = 1;
    q.push(mp(0, 0));
    pii node;
    while(!q.empty()){
        node = q.front();
        q.pop();

        if(node.F==N-1) break;

        for(int i=node.F+1; i<=node.F+6 && i<=N-1; i++){
            if(!visited[i]){
                visited[i] = 1;
                if(moves[i]!=-1){
                    q.push(mp(moves[i], node.S+1));
                }else{
                    q.push(mp(i, node.S+1));
                }
            }
        }
    }
    return node.S;
}

int main(){
    int N = 30;
    int moves[N];
    memset(moves, -1, sizeof(moves));
    
	// Ladders
    moves[2] = 21;
    moves[4] = 7;
    moves[10] = 25;
    moves[19] = 28;
 
    // Snakes
    moves[26] = 0;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;

    cout<<"Min dice throws: "<<minDiceThrows(moves, N)<<endl;
}

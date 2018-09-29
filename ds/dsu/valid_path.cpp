#include <bits/stdc++.h>
using namespace std;
#define MAX 1005
#define INF INT_MAX
#define NINF INT_MIN
#define pb push_back

vector<int> par(MAX);
vector<int> rnk(MAX, 1);
vector<bool> vis(MAX, false);
vector<int> xC(MAX);
vector<int> yC(MAX);

int X, Y, N, R;

void init(int N){
    for(int i=0; i<N; i++) par[i] = i;
    rnk.clear();
    rnk.resize(MAX, 1);
    vis.clear();
    vis.resize(MAX, false);
}

int find(int x){
    while(par[x]!=x){
        par[x] = find(par[x]);
        x = par[x];
    }
    return x;
}

int make_union(int x, int y){
    int xp = find(x);
    int yp = find(y);
    int fpar;
    if(xp==yp) fpar=xp;
    else{
        if(rnk[xp]>rnk[yp]){
            par[yp] = xp;
            fpar = xp;
        }else if(rnk[yp]>rnk[xp]){
            par[xp] = yp;
            fpar = yp;
        }else{
            rnk[yp]++;
            par[xp] = yp;
            fpar = yp;
        }
    }
    return fpar;
}

bool findBlockage(int root){
    int top = 0, bottom = INF, left = INF, right = 0;

    int x, y;
    for(int i=0; i<N; i++){
        if(par[i]==root){
            x = xC[i];
            y = yC[i];

            top = max(top, y+R);
            bottom = min(bottom, y-R);
            left = min(left, x-R);
            right = max(right, x+R);
        }
    }
    
    if(top>=Y && right>=X) return true;
    if(left<=0 && right>=X) return true;
    if(left<=0 && bottom<=0) return true;
    if(top>=Y && bottom<=0) return true;
    return false;
}

void printVec(vector<int> vec, int n){
    for(int i=0; i<N; i++){
        cout<<vec[i];
    }
    cout<<endl;
}

bool isPossible(){
    int x1, y1, x2, y2;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            x1 = xC[i];
            y1 = yC[i];

            x2 = xC[j];
            y2 = yC[j];
            
            if((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)<=4*R*R){
                make_union(i, j);
            }
        }
    }
    
    for(int i=0; i<N; i++){
        if(!vis[par[i]]){
            vis[par[i]] = 1;
            bool ret = findBlockage(par[i]);
            if(ret) return false;
        }
    }
    return true;
}

int main(){
    cin>>X>>Y>>N>>R;
    init(N);
    for(int i=0; i<N; i++){
        cin>>xC[i];
    }
    for(int i=0; i<N; i++){
        cin>>yC[i];
    }
    if(isPossible()) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

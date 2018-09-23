#include <bits/stdc++.h>
using namespace std;
#define MAX 200005

int arr[MAX];
int tree[2*MAX];

void printVec(int start, int end){
    for(int i=start; i<=end; i++){
        cout<<tree[i]<<" ";
    }
    cout<<endl;
}

void build(int node, int start, int end){
    if(start>end) return;
    if(start==end){
        tree[node] = arr[start];
    }else{
        int mid = (start+end)/2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = min(tree[2*node], tree[2*node+1]);
    }
}

void update(int node, int start, int end, int idx, int val){
    if(start>end) return;
    if(start==end){
        tree[node] = val;
        arr[idx] = val;
    }else{
        int mid = (start+end)/2;
        if(start<=idx && idx<=mid){
            update(2*node, start, mid, idx, val);
        }else{
            update(2*node+1, mid+1, end, idx, val);
        }
        tree[node] = min(tree[2*node], tree[2*node+1]);
    }
}

int query(int node, int start, int end, int l, int r){
    if(l>end || r<start) return INT_MAX;
    if(l<=start && end<=r){
        return tree[node];
    }else{
        int mid = (start+end)/2;
        int p1 = query(2*node, start, mid, l, r);
        int p2 = query(2*node+1, mid+1, end, l, r);
        return min(p1, p2);
    }
}

int main(){
    for(int i=0; i<5; i++){
        arr[i] = i+1;
    }
    int ans;
    build(1, 0, 4);
    printVec(1, 10);
    ans = query(1, 0, 4, 2, 3);
    cout<<ans<<endl;
    ans = query(1, 0, 4, 1, 4);
    cout<<ans<<endl;
}

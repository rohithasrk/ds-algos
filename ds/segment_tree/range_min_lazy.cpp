#include <bits/stdc++.h>
using namespace std;
#define MAX 200005

int arr[MAX];
int tree[2*MAX];
int lazy[2*MAX];

void build(int node, int start, int end){
    if(start>end) return;
    if(start==end) tree[node] = arr[start];
    else{
        int mid = (start+end)/2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

void updateRange(int node, int start, int end, int l, int r, int val){
    if(lazy[node]!=0){
        tree[node] += lazy[node];
        if(start!=end){
            lazy[2*node] = lazy[node];
            lazy[2*node+1] = lazy[node];
        }
        lazy[node] = 0;
    }
    if(start>end || start>r || end<l) return;
    if(start>=l && end<=r){
        tree[node] += val;
        if(start!=end){
            lazy[2*node] += val;
            lazy[2*node+1] += val;
        }
        return;
    }else{
        int mid = (start+end)/2;
        updateRange(2*node, start, mid, l, r, val);
        updateRange(2*node+1, mid+1, end, l, r, val);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

int query(int node, int start, int end, int l, int r){
    if(start>end || end<l || start>r) return INT_MAX;
    if(lazy[node]!=0){
        tree[node] += lazy[node];
        if(start!=end){
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start>=l && end<=r){
        return tree[node];
    }else{
        int mid = (start+end)/2;
        int p1 = query(2*node, start, mid, l, r);
        int p2 = query(2*node+1, mid+1, end, l, r);
        return min(p1, p2);
    }
}

int main(){
    for(int i=0; i<10; i++){
        arr[i] = 12-i;
    }
    build(1, 0, 9);
    int ans = query(1, 0, 9, 2, 4);
    cout<<ans<<endl;
    updateRange(1, 0, 9, 2, 6, 1);
    ans = query(1, 0, 9, 2, 4);
    cout<<ans<<endl;
    updateRange(1, 0, 9, 1, 3, -2);
    ans = query(1, 0, 9, 1, 5);
    cout<<ans<<endl;
}

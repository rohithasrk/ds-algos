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

// Start and end indices of the arr
void build(int node, int start, int end){
    if(start>end) return;
    else if(start==end){
        tree[node] = arr[start];
    }else{
        int mid = start + (end-start)/2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = tree[2*node]+tree[2*node+1];
    }
}

int query(int node, int start, int end, int l, int r){
    if(r<start || end<l){
        return 0;
    }
    if(l<=start && end<=r){
        return tree[node];
    }
    int mid = (start+end)/2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return (p1+p2);
}

void update(int node, int start, int end, int idx, int val){
   if(start==end){
       arr[idx] = val;
       tree[node] = val;
   }else{
       int mid = (start+end)/2;
       if(start<=idx && idx<=mid){
           update(2*node, start, mid, idx, val);
       }else{
           update(2*node+1, mid+1, end, idx, val);
       }
       tree[node] = tree[2*node] + tree[2*node+1];
   } 
}

int main(){
    int ans;
    build(1, 0, 5);
    update(1, 0, 5, 1, 2);
    ans = query(1, 0, 5, 0, 2);
    cout<<ans<<endl;
    update(1, 0, 5, 4, 4);
    ans = query(1, 0, 5, 0, 3);
    cout<<ans<<endl;
    printVec(0, 20);
}

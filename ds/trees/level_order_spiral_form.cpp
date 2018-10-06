#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define f front
#define p push

typedef pair<int, int> pii;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void printVec(vector<int> &vec){
    for(int i=0; i<vec.size(); i++) cout<<vec[i]<<" ";
    cout<<endl;
}

void levelOrderSpiral(TreeNode *root){
    if(!root) return;
    unordered_map<int, vector<int>> lmap;
    queue<pair<TreeNode*, int>> q;
    q.p(mp(root, 1));
    TreeNode* tmp;
    int l;
    int max_l = 0;
    while(!q.empty()){
        tmp = q.f().F;
        l = q.f().S;
        max_l = max(l, max_l);
        q.pop();
        if(l%2==0) lmap[l].insert(lmap[l].begin(), tmp->val);
        else lmap[l].pb(tmp->val);
        if(tmp->left) q.p(mp(tmp->left, l+1));
        if(tmp->right) q.p(mp(tmp->right, l+1));
    }
    for(int i=1; i<=max_l; i++){
        printVec(lmap[i]);
    }
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    levelOrderSpiral(root);
}

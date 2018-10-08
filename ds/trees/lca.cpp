#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

TreeNode *LCA(TreeNode* root, int val1, int val2){
    if(!root) return NULL;
    if(root->val==val1 || root->val==val2) return root;
    TreeNode* L = LCA(root->left, val1, val2);
    TreeNode* R = LCA(root->right, val1, val2);
    if(L && R) return root;
    else return L? L: R;
}

bool find(TreeNode* root, int val){
    if(!root) return false;
    if(root->val==val) return true;
    return (find(root->left, val) || find(root->right, val));
}

int lca(TreeNode* root, int val1, int val2){
    if(!find(root, val1) || !find(root, val2)) return -1;
    TreeNode* ans = LCA(root, val1, val2);
    if(!ans) return -1;
    return ans->val;
}

int main(){
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    cout<<lca(root, 3, 4)<<endl;
    cout<<lca(root, 1, 6)<<endl;
}

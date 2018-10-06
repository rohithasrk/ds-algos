#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

int maxSumPath(TreeNode *root, int &res){
    if(root==NULL) return 0;
    int l = maxSumPath(root->left, res);
    int r = maxSumPath(root->right, res);

    int max_single = max(max(l, r) + root->val, root->val);

    int max_top = max(max_single, l+r+root->val);

    res = max(res, max_top);

    return max_single;
}

int main(){
    int res = INT_MIN;
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(2);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(-25);
    root->right->right->left = new TreeNode(3);
    root->right->right->right = new TreeNode(4);
    maxSumPath(root, res);
    cout<<res<<endl;
}

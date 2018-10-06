#include <bits/stdc++.h>
using namespace std;
#define pb push_back

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

int diameter(TreeNode* root, int &h){
    int lh = 0, rh = 0;
    if(!root){
        h = 0;
        return 0;
    }
    int ld = diameter(root->left, lh);
    int rd = diameter(root->right, rh);

    h = max(lh, rh) + 1;

    return max(lh+rh+1, max(ld, rd));
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    int h = 0;
    cout<<diameter(root, h)<<endl;
}

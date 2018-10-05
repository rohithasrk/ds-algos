#include <bits/stdc++.h>
using namespace std;
#define pb push_back

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

vector<int> inOrder(TreeNode *root){
    vector<int> res;
    if(!root) return res;
    TreeNode *current, *pre;
    current = root;
    while(current!=NULL){
        if(current->left==NULL){
            res.pb(current->val);
            current = current->right;
        }else{
            pre = current->left;
            while(pre->right!=NULL && pre->right!=current) pre = pre->right;
            if(pre->right==NULL){
                pre->right = current;
                current = current->left;
            }else{
                pre->right = NULL;
                res.pb(current->val);
                current = current->right;
            }
        }
    }
}

void printVec(vector<int> &vec){
    for(int i=0; i<vec.size(); i++) cout<<vec[i]<<" ";
    cout<<endl;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    vector<int> vec = inOrder(root);
    printVec(vec);
}

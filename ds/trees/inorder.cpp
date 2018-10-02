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
    stack<TreeNode*> st;
    set<TreeNode*> vis;
    st.push(root);
    TreeNode *node;
    while(!st.empty()){
        node = st.top();
        if(node->left && vis.find(node)==vis.end()){
            st.push(node->left);
            vis.insert(node);
        }else{
            res.pb(node->val);
            st.pop();
            if(node->right) st.push(node->right);
        }
    }
    return res;
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

#include <bits/stdc++.h>
using namespace std;
#define pb push_back

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

vector<int> postOrder(TreeNode *root){
    vector<int> res;
    if(!root) return res;
    stack<TreeNode*> st;
    set<TreeNode*> vis;
    st.push(root);
    TreeNode *node;
    while(!st.empty()){
        node = st.top();
        if(((!node->right || (node->right && vis.find(node->right)!=vis.end())) &&
           (!node->left || (node->left && vis.find(node->left)!=vis.end())))){
            res.pb(node->val);
            st.pop();
        }else{
            if(node->right){
                vis.insert(node->right);
                st.push(node->right);
            }
            if(node->left){
                vis.insert(node->left);
                st.push(node->left);
            }
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
    vector<int> vec = postOrder(root);
    printVec(vec);
}

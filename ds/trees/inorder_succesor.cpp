#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int x): data(x), left(NULL), right(NULL) {};
};

Node* tmp = new Node(0);

Node* leftMostNode(Node* root){
    while(root!=NULL && root->left!=NULL){
        root = root->left;
    }
    return root;
}

Node* rightMostNode(Node *root){
    while(root!=NULL && root->right!=NULL){
        root = root->right;
    }
    return root;
}

Node* findInorder(Node* root, Node* x){
    if(!root) return NULL;
    if(root==x || (tmp=findInorder(root->left, x)) ||
                  (tmp=findInorder(root->right, x)))
    {
        if(tmp){
            if(root->left==tmp){
                cout<<root->data<<endl;
                return NULL;
            }
        }
        return root;
    }
}

Node* inorderSuccessor(Node* root, Node* x){
    if(x->right!=NULL){
        cout<<leftMostNode(x->right)->data<<endl;
    }
    if(x->right==NULL){
        Node *rightMost = rightMostNode(root);
        if(rightMost==x) cout<<"Not possible"<<endl;
        else{
            findInorder(root, x);
        }
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    inorderSuccessor(root, root->right);
    inorderSuccessor(root, root->left->left);
    inorderSuccessor(root, root->right->right);
}

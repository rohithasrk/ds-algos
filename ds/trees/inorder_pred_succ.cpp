#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int x): data(x), left(NULL), right(NULL) {};
};

Node* tmp;

void init(){
    tmp = NULL;
}

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

Node* findInorderSucc(Node* root, Node* x){
    if(!root) return NULL;
    if(root==x || (tmp=findInorderSucc(root->left, x)) ||
                  (tmp=findInorderSucc(root->right, x)))
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

Node* findInorderPred(Node* root, Node* x){
    if(!root) return NULL;
    if(root==x || (tmp=findInorderPred(root->left, x)) ||
                  (tmp=findInorderPred(root->right,x)))
    {
        if(tmp){
            if(root->right==tmp){
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
    else if(x->right==NULL){
        Node *rightMost = rightMostNode(root);
        if(rightMost==x) cout<<"Not possible"<<endl;
        else{
            findInorderSucc(root, x);
        }
    }
}

Node *inorderPredecessor(Node* root, Node *x){
    if(x->left!=NULL){
        cout<<rightMostNode(x->left)->data<<endl;
    }else if(x->left==NULL){
        Node *leftMost = leftMostNode(root);
        if(leftMost==x) cout<<"Not possible"<<endl;
        else{
            findInorderPred(root, x);
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

    init();
    inorderPredecessor(root, root->right);
    inorderPredecessor(root, root->left->left);
    inorderPredecessor(root, root->right->right);

    cout<<endl;

    init();
    inorderSuccessor(root, root->right);
    inorderSuccessor(root, root->left->left);
    inorderSuccessor(root, root->right->right);
}

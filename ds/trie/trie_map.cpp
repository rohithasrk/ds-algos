#include <bits/stdc++.h>
using namespace std;

struct Trie{
    bool isEnd;

    unordered_map<char, Trie*> children;
};

struct Trie* getNode(){
    Trie* node = new Trie;
    node->isEnd = false;
    return node;
}

void insert(Trie* &root, string str){
    if(root==nullptr){
        root = getNode();
    }
    Trie* tmp = root;
    for(int i=0; i<str.length(); i++){
        char x = str[i];
        
        if(tmp->children.find(x)==tmp->children.end()){
            tmp->children[x] = getNode();
        }
        tmp = tmp->children[x];
    }
    tmp->isEnd = true;
}

bool search(Trie* root, string str){
    if(root==nullptr) return false;

    Trie* tmp = root;

    for(int i=0; i<str.length(); i++){
        tmp = tmp->children[str[i]];

        if(tmp==nullptr) return false;
    }
    return tmp->isEnd;
}

int main(){
    Trie* root = nullptr;

    insert(root, "rohith");

    insert(root, "for");

    insert(root, "the");

    insert(root, "rowing");

    cout<<search(root, "rohith")<<endl;
}

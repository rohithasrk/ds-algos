#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEnd;
};

struct TrieNode *getNode(void){
    struct TrieNode *node = new TrieNode;

    node->isEnd = false;

    for(int i=0; i<ALPHABET_SIZE; i++){
        node->children[i] = NULL;
    }

    return node;
}

void insert(struct TrieNode *root, string key){
    struct TrieNode *node = root;

    for(int i=0; i<key.length(); i++){
        int index = key[i] - 'a';
        if(!node->children[index]){
            node->children[index] = getNode();
        }
        node = node->children[index];
    }
    node->isEnd = true;
}

bool search(struct TrieNode *root, string key){
    struct TrieNode* node = root;

    for(int i=0; i<key.length(); i++){
        int index = key[i] - 'a';
        if(!node->children[index]) return false;

        node = node->children[index];
    }

    return (node!=NULL && node->isEnd);
}

int main(){
    string keys[] = {"the", "a", "there", "answer", "any", "by",
                     "bye", "their"};
    int n = sizeof(keys)/sizeof(keys[0]);

    struct TrieNode *root = getNode();

    for(int i=0; i<n; i++){
        insert(root, keys[i]);
    }

    search(root, "the")? cout<<"Yes\n": cout<<"No\n";
    search(root, "these")? cout<<"Yes\n": cout<<"No\n";
    return 0;
}

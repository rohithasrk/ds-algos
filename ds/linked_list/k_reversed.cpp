#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

ListNode* reverseList(ListNode* A, int B){
    ListNode* current = A;
    ListNode* next = NULL;
    ListNode* prev = NULL;
    int count = 0;

    while(count<B){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    if(next!=NULL) A->next = reverseList(next, B);
    return prev;
}

void printLL(ListNode* A){
    ListNode* itr = A;
    while(itr!=NULL){
        cout<<itr->val<<" ";
        itr = itr->next;
    }
    cout<<endl;
}

int main(){
    ListNode* root = new ListNode(0);
    root->next = new ListNode(1);
    root->next->next = new ListNode(2);
    root->next->next->next = new ListNode(3);
    printLL(reverseList(root, 2));
}

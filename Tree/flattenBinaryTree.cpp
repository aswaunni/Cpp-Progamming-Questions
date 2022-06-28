/*
Given a binary tree, flatten it into a linked list in place. After flattening, left of each node should point to NULL
and right should containext nod in preorder sequence.
*/

#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node* left;
    Node* right;
    int data;
    
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* flatten(Node* r) {
    if (r == NULL)
        return NULL;
    
    Node* lHead = flatten(r->left);
    Node* rHead = flatten(r->right);
    
    r->left = NULL;
    r->right = lHead;
    
    Node* t = r;
    while(t->right != NULL)
        t = t->right;
        
    t->right = rHead;
    
    return r;
}

// OR 

Node* flatten(Node* r, Node* prev) {
    if (r == NULL)
        return prev;
        
    prev = flatten(r->right, prev);
    prev = flatten(r->left, prev);
    
    r->right = prev;
    r->left = NULL;
    prev = r;
    return prev;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    Node* prev = NULL;
    Node* r = flatten(root, prev);
    
    while(r) {
        cout << r->data << " ";
        r = r->right;
    }
    return 0;
}

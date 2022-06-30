/*
Given a binary tree. Check whether it is a BST or not.
Note: We are considering that BSTs can not contain duplicate Nodes.

Example 1:

Input: 2 1 3
Output: 1 

Example 2:

Input: 3 2 5 1 4
Output: 0 (Since 4 is on left side of 3)

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

bool checkIfBST(Node* r, int mn, int mx) {
    if (r == NULL)
        return true;
        
    if (r->data < mx && r->data > mn)
        return checkIfBST(r->left, mn, r->data) & checkIfBST(r->right, r->data, mx);
    return false;
}

int main()
{
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->right->left = new Node(3);
    root->right->right = new Node(8);
    
    cout << checkIfBST(root, INT_MIN, INT_MAX) << endl;
    return 0;
}

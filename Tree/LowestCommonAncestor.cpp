/*
   Given a Binary Search Tree (with all values unique) and two node values. Find the Lowest Common Ancestors of the two nodes in the Binary tree.

Example 1:

Input:
    5
  /    \
 4      6
/        \
3          7
 \
  8
n1 = 7, n2 = 8
Output: 5
Example 2:

Input:
  2
 /  \
1    3
n1 = 1, n2 = 3
Output: 2
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

Node* LCA(Node* r, int n1, int n2) {
    if (r == NULL)
        return NULL;
        
    if (r->data == n1 || r->data == n2)
        return r;
        
    Node* leftLCA = LCA(r->left, n1, n2);
    Node* rightLCA = LCA(r->right, n1, n2);
    
    if (leftLCA && rightLCA)
        return r;
        
    if(leftLCA)
        return leftLCA;
        
    return rightLCA;
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
    
    cout << LCA(root, 3, 4)->data;
    return 0;
}

/*
Distance between 2 nodes is thre minimum edges between 2 nodes in a binary tree.
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

int findDist(Node* r, int k, int dist) {
    if (r == NULL)
        return -1;
        
    if (r->data == k)
        return dist;
        
    int left = findDist(r->left, k, dist+1);
    if (left != -1)
        return left;
    
    return findDist(r->right, k, dist+1);
}

int distBtwNodes(Node* r, int n1, int n2) {
    Node* lca = LCA(r, n1, n2);
    
    int d1 = findDist(lca, n1, 0);
    int d2 = findDist(lca, n2, 0);
    
    return d1+d2;
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
    
    cout << distBtwNodes(root, 3, 2);
    return 0;
}

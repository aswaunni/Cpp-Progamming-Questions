/*
For each node, the difference between the heights of left subtree and right subtree <= 1.
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

bool checkBalanced(Node* r, int& height) {
    if (r == NULL)
        return true;
        
    int lh = 0, rh = 0;
    
    if (!(checkBalanced(r->left, lh) && checkBalanced(r->right, rh)))
        return false;

    height = 1+max(lh, rh);
    if (abs(lh - rh) > 1)
        return false;
    return true;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->right = new Node(5);
    
    int h = 0;
    cout << checkBalanced(root, h);
    return 0;
}

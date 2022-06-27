/*
Diameter - Longest path between any 2 nodes of a binary tree.
*/

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

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

int height(Node* r, int& diameter) {
    if (r == NULL)
        return 0;
    
    int l_height = height(r->left, diameter);
    int r_height = height(r->right, diameter);
    
    diameter = max(diameter, l_height + r_height + 1);
    return 1 + max(l_height, r_height);
}

// OR

int diameter(Node* r, int& h) {
    if (r == NULL)
        return 0;
        
    int lh = 0, rh = 0;
    int lDiameter = diameter(r->left, lh);
    int rDiameter = diameter(r->right, rh);
    
    h = max(lh, rh) + 1;
    
    return max(lh+rh+1, max(lDiameter, rDiameter));
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
    
    int ans = 0; 
    height(root, ans);
    cout << ans;
    
    ans = 0;
    cout << endl << diameter(root, ans);
    return 0;
}

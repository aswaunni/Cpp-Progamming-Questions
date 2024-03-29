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

int countNodes(Node* r) {
    if (r == NULL)
        return 0;

    return 1 + countNodes(r->left) + countNodes(r->right);
}

// OR (Efficient)

int countNodes(TreeNode* root) {
    if (!root)
        return 0;
    
    int lh = 1, rh = 1;
    TreeNode *r = root, *l = root;
    while (l = l->left)
        ++lh;
    while (r = r->right)
        ++rh;
    
    if (lh == rh)
        return (1 << lh) - 1;
    
    return 1 + countNodes(root->left) + countNodes(root->right);
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
    
    cout << countNodes(root);
    return 0;
}


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

struct Info {
    int mn;
    int mx;
    int size;
    bool isBST;
};

Info largestBST(Node* r) {
    if (r == NULL)
        return {INT_MAX, INT_MIN, 0, true};
    
    if (r->left == NULL && r->right == NULL)
        return {r->data, r->data, 1, true};
        
    Info li = largestBST(r->left);
    Info ri = largestBST(r->right);
    
    int sz = li.size + ri.size + 1;
    if (li.isBST && ri.isBST && r->data > li.mx && r->data < ri.mn) {
        return {min(li.mn, r->data), max(ri.mx, r->data), sz, true}; // r->data required in case of single child node
    }
    return {0, 0, max(li.size, ri.size), false};
}

int main()
{
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(3);
    root->right->right = new Node(7);
    
    cout << largestBST(root).size << endl;
    return 0;
}

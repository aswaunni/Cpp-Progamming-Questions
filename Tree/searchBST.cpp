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

Node* searchBST(Node* r, int x) {
    if (r == NULL)
        return NULL;
    
    if (x == r->data)
        return r;
    else if (x < r->data)
        return searchBST(r->left, x);
    return searchBST(r->right, x);
}

int main()
{
    Node* root = new Node(5);
    root->left = new Node(1);
    root->right = new Node(7);
    root->left->right = new Node(3);
    root->left->right->left = new Node(2);
    root->left->right->right = new Node(4);
    
    Node* ans = searchBST(root, 0);
    cout << (ans ? ans->data : -1) << endl;
    return 0;
}

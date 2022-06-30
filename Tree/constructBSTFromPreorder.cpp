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

Node* constructBSTFromPreorder(int pre[], int& preIdx, int x, int mn, int mx, int n) {
    if (preIdx >= n)
        return NULL;
        
    Node* r = NULL;
    if (x > mn && x < mx) {
        r = new Node(x);
        preIdx++;
        if (preIdx < n) {
            r->left = constructBSTFromPreorder(pre, preIdx, pre[preIdx], mn, x, n);
            r->right = constructBSTFromPreorder(pre, preIdx, pre[preIdx], x, mx, n);
        }
    }
    return r;
}

void preOrder(Node* r) {
    if (r == NULL)
        return;
    cout << r->data << " ";
    preOrder(r->left);
    preOrder(r->right);
}

int main()
{
    int pre[] = {10, 2, 1, 13, 11};
    int preIdx = 0;
    Node* root = constructBSTFromPreorder(pre, preIdx, pre[0], INT_MIN, INT_MAX, 5);
    preOrder(root);
    return 0;
}

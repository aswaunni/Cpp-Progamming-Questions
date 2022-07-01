/*
2 nodes of a BST are swapped. Restore the BST/
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

struct Info {
    int mn;
    int mx;
    int size;
    bool isBST;
};

void calcPointers(Node* r, Node* &first, Node* &mid, Node* &last, Node* & prev) {
    if (r == NULL)
        return;
        
    calcPointers(r->left, first, mid, last, prev);
    if (prev && prev->data > r->data) {
        if (!first) {
            first = prev;
            mid = r;
        } else {
            last = r;
        }
    }
    prev = r;
    calcPointers(r->right, first, mid, last, prev);
}

void restoreBST(Node* r) {
    Node* first = NULL, *mid = NULL, *last = NULL, *prev = NULL;
    calcPointers(r, first, mid, last, prev);
    
    if (first && last) {
        swap(first->data, last->data);
    } else if (first && mid) {
        swap(first->data, mid->data);
    }
}

void inOrder(Node* r) {
    if (r == NULL)
        return;
    inOrder(r->left);
    cout << r->data << " ";
    inOrder(r->right);
}

int main()
{
    Node* root = new Node(5);
    root->left = new Node(8);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(3);
    
    inOrder(root); // Idea is that inorder is always in increasing order
    
    restoreBST(root);
    
    cout << endl;
    inOrder(root);
    return 0;
}

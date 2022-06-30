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

Node* minValueNode(Node* r) {
    while (r && r->left)
        r = r->left;
    return r;
}

Node* deleteInBST(Node* r, int x) {
    if (r == NULL)
        return NULL;
    
    if (x < r->data)
        r->left = deleteInBST(r->left, x);
    else if (x > r->data)
        r->right = deleteInBST(r->right, x);
    else {
        // Handles cases when there are no children and 1 child
        if (r->left == NULL) {
            Node* temp = r->right;
            free(r);
            return temp;
        } else if (r->right == NULL) {
            Node* temp = r->left;
            free(r);
            return temp;
        }
        
        // Handles case when tere are 2 children
        Node* temp = minValueNode(r->right);
        r->data = temp->data;
        r->right = deleteInBST(r->right, temp->data);
    }
    return r;
}

int main()
{
    Node* root = new Node(5);
    root->left = new Node(1);
    root->right = new Node(7);
    root->left->right = new Node(3);
    root->left->right->left = new Node(2);
    root->left->right->right = new Node(4);
    
    root = deleteInBST(root, 3);
    return 0;
}

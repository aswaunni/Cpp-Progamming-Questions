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

void printSubtreeNodes(Node* r, int k) {
    if (r == NULL || k < 0)
        return;
        
    if (k == 0) {
        cout << r->data << " ";
        return;
    }
    
    printSubtreeNodes(r->left, k-1);
    printSubtreeNodes(r->right, k-1);
}

int printNodesAtK(Node* r, Node* target, int k) {
    if (r == NULL)
        return -1;
        
    if (r == target) {
        printSubtreeNodes(r, k);
        return 0;
    }
    
    int dl = printNodesAtK(r->left, target, k);
    if (dl != -1) {
        if ((dl + 1) == k)
            cout << r->data << " ";
        else
            printSubtreeNodes(r->right, k-dl-2);
        return 1+dl;
    }

    int dr = printNodesAtK(r->right, target, k);
    if (dr != -1) {
        if ((dr + 1) == k)
            cout << r->data << " ";
        else
            printSubtreeNodes(r->left, k-dr-2);
        return 1+dr;
    }
    
    return -1;
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
    
    printNodesAtK(root, root->left->left, 4);
    return 0;
}

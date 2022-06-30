/*
For given root nodes of 2 BSTs, print if the BSTs are identcal or not.
Identical BSTs are structurally identical and have equal values for the nodes in the structure.
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

bool identicalBST(Node* r1, Node* r2) {
    if (r1 == NULL && r2 == NULL)
        return true;
    
    if (r1 == NULL || r2 == NULL || r1->data != r2->data)
        return false;
    
    
    return identicalBST(r1->left, r2->left) && identicalBST(r1->right, r2->right);
}

int main()
{
    Node* root1 = new Node(4);
    root1->left = new Node(2);
    root1->right = new Node(7);
    root1->left->left = new Node(1);
    root1->right->left = new Node(3);
    root1->right->right = new Node(8);
    
    
    Node* root2 = new Node(4);
    root2->left = new Node(2);
    root2->right = new Node(7);
    root2->left->left = new Node(1);
    root2->right->left = new Node(3);
    root2->right->right = new Node(8);
    
    cout << identicalBST(root1, root2) << endl;
    return 0;
}

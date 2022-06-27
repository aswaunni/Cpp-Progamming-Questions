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

void rightView(Node* r) {
    if (r == NULL)
        return;
        
    queue<Node*> q;
    q.push(r);
    q.push(NULL);

    while(!q.empty()) {
        Node* f = q.front();
        q.pop();
        
        if (f != NULL) {
            if (q.front() == NULL)
                cout << f->data << " ";
                
            if(f->left)
                q.push(f->left);
            if(f->right)
                q.push(f->right);
        } else if (!q.empty())
            q.push(NULL);
    }
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
    
    rightView(root);
    return 0;
}

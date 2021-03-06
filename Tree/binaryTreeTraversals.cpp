/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

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

void preOrder(Node* r) {
    if (r == NULL)
        return;
    cout << r->data << " ";
    preOrder(r->left);
    preOrder(r->right);
}

void inOrder(Node* r) {
    if (r == NULL)
        return;
    inOrder(r->left);
    cout << r->data << " ";
    inOrder(r->right);
}

void postOrder(Node* r) {
    if (r == NULL)
        return;
    postOrder(r->left);
    postOrder(r->right);
    cout << r->data << " ";
}

void levelOrder(Node* r) {
    if (r == NULL)
        return;
    queue<Node*> q;
    q.push(r);
    q.push(NULL);

    while(!q.empty()) {
        Node* f = q.front();
        q.pop();
        if (f != NULL) {
            cout << f->data << " ";

            if(f->left) q.push(f->left);
            if(f->right) q.push(f->right);
        } else if (!q.empty())
            q.push(NULL);
    }
}

void zigzagTraversal(Node* r) { // left to right on one level and right to lwft on next level
    if (r == NULL)
        return;
        
    bool leftToRight = true;
    stack<Node*> sCur, sNext;
    
    sCur.push(r);
    
    while(!sCur.empty()) {
        Node* t = sCur.top();
        sCur.pop();
        if (t) {
            cout << t->data << " ";
            if (leftToRight) {
                if (t->left) sNext.push(t->left);
                if (t->right) sNext.push(t->right);
            } else {
                if (t->right) sNext.push(t->right);
                if (t->left) sNext.push(t->left);
            }
        }
        
        if (sCur.empty()) {
            leftToRight = !leftToRight;
            swap(sCur, sNext);
        }
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
    
    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    levelOrder(root);
    cout << endl;
    zigzag(root);
    return 0;
}

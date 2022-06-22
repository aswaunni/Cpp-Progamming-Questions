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

int sumKthLevel(Node* r, int k) {
    if (r == NULL)
        return -1;
    queue<Node*> q;
    q.push(r);
    q.push(NULL);
    int level = 0, sum = 0;

    while(!q.empty()) {
        Node* f = q.front();
        q.pop();
        if (f != NULL) {
            if (level == k)
                sum += f->data;

            if(f->left) q.push(f->left);
            if(f->right) q.push(f->right);
        } else if (!q.empty()) {
            q.push(NULL);
            level++;
        }
    }
    return sum;
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
    
    cout << sumKthLevel(root, 2);
    return 0;
}

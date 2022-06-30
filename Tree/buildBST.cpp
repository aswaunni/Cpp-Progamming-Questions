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

Node* insertBST(Node* r, int x) {
    if (r == NULL)
        return new Node(x);
        
    if (x < r->data)
        r->left = insertBST(r->left, x);
    else
        r->right = insertBST(r->right, x);
    return r;
}

Node* buildBST(vector<int> v) {
    if (v.size() == 0)
        return NULL;
        
    Node* root = NULL;
    root = insertBST(root, v[0]);
    for(int i = 1; i < v.size(); i++)
        insertBST(root, v[i]);
    return root;
}

// OR

Node* buildBST(vector<int> v) {
    if (v.size() == 0)
        return NULL;
        
    Node* root = new Node(v[0]);
    for(int i = 1; i < v.size(); i++) {
        Node* t = root;
        while(t) {
            if (v[i] < t->data) {
                if (t->left) t = t->left;
                else {
                    t->left = new Node(v[i]);
                    break;
                }
            } else {
                if (t->right) t = t->right;
                else {
                    t->right = new Node(v[i]);
                    break;
                }
            }
        }
        
    }
    return root;
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

int main()
{
    vector<int> v = {5, 1, 3, 4, 2, 7};
    
    Node* root = buildBST(v);
    levelOrder(root);
    return 0;
}

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

void postOrderPrint(Node* r) {
    if (r == NULL)
        return;
    postOrderPrint(r->left);
    postOrderPrint(r->right);
    cout << r->data << " ";
}

int search(int in[], int cur, int st, int end) {
    for (int i = st; i <= end; i++) {
        if (in[i] == cur)
            return i;
    }
    return -1;
}
Node* buildTree(int post[], int in[], int st, int end) {
    static int idx = 6;
    if (st > end)
        return NULL;

    int cur = post[idx];
    idx--;
    Node* r = new Node(cur);
    if (st == end)
        return r;
    
    int pos = search(in, cur, st, end);
    r->right = buildTree(post, in, pos+1, end);
    r->left = buildTree(post, in, st, pos-1);

}

int main()
{
    int postOrder[] = {4, 5, 2, 6, 7, 3, 1};
    int inOrder[] = {4, 2, 5, 1, 6, 3, 7};
    
    Node* root = buildTree(postOrder, inOrder, 0, 6);
    
    postOrderPrint(root);
    return 0;
}

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

void preOrderPrint(Node* r) {
    if (r == NULL)
        return;
    cout << r->data << " ";
    preOrderPrint(r->left);
    preOrderPrint(r->right);
}

int search(int in[], int cur, int st, int end) {
    for (int i = st; i <= end; i++) {
        if (in[i] == cur)
            return i;
    }
    return -1;
}
Node* buildTree(int pre[], int in[], int st, int end) {
    static int idx = 0;
    if (st > end)
        return NULL;

    int cur = pre[idx];
    idx++;
    Node* r = new Node(cur);
    if (st == end)
        return r;
    
    int pos = search(in, cur, st, end);
    r->left = buildTree(pre, in, st, pos-1);
    r->right = buildTree(pre, in, pos+1, end);

}

int main()
{
    int preOrder[] = {1, 2, 4, 5, 3, 6, 7};
    int inOrder[] = {4, 2, 5, 1, 6, 3, 7};
    
    Node* root = buildTree(preOrder, inOrder, 0, 6);
    
    preOrderPrint(root);
    return 0;
}

/******************************************************************************
[EASY]

This problem was asked by Google.

A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.

Given the root to a binary tree, count the number of unival subtrees.

For example, the following tree has 5 unival subtrees:

   0
  / \
 1   0
    / \
   1   0
  / \
 1   1

*******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct node{
    int val;
    node *left, *right;
};

node* newNode(int val){
    auto root = new node;
    root->val = val;
    root->left = root->right = nullptr;
    return root;
}

int cnt = 0;

bool countUnival(node* root) {
    if (!root)
        return true;
        
    bool l = countUnival(root->left);
    bool r = countUnival(root->right);
    
    if (l == false || r == false || (root->left && root->left->val != root->val) || (root->right && root->right->val != root->val))
        return false;
        
    cnt++;
    return true;
}

int main(){
    auto root = newNode(0);
    root->left = newNode(1);
    root->right = newNode(0);
    root->right->left = newNode(1);
    root->right->right = newNode(0);
    root->right->left->left = newNode(1);
    root->right->left->right = newNode(1);
    
    countUnival(root);
    
    cout << cnt << "\n";
	    
	return 0;
}

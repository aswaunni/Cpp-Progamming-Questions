/*
Given a binary tree, find its minimum depth.

Example 1:
Input:
            1
          /   \
         3     2
        /
       4           

Output: 2

Example 2:
Input:
             10
          /     \
        20       30
          \        \   
          40        60 
                   /
                  2 

Output: 3
*/

int minDepth(Node *root) {
    if (root == NULL)
        return INT_MAX;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return 1+min(minDepth(root->left), minDepth(root->right));
}

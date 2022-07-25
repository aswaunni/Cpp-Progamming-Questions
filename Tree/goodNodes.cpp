/*
Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.

Example 1:
Input: root = [3,1,4,3,null,1,5]
Output: 4

Example 2:
Input: root = [3,3,null,4,2]
Output: 3

Example 3:
Input: root = [1]
Output: 1
*/

int dfs(TreeNode* r, int mx) {
    if (r == NULL)
        return 0;
    
    return dfs(r->left, max(mx, r->val)) + dfs(r->right, max(mx, r->val)) + (r->val >= mx);
}

int goodNodes(TreeNode* root) {
    return dfs(root, INT_MIN);
}

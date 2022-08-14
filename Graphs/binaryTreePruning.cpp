/*
Given the root of a binary tree, return the same tree where every subtree (of the given tree) not containing a 1 has been removed.

A subtree of a node node is node plus every node that is a descendant of node.

 

Example 1:


Input: root = [1,null,0,0,1]
Output: [1,null,0,null,1]
Explanation: 
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.
Example 2:


Input: root = [1,0,1,0,0,0,1]
Output: [1,null,1,null,1]
Example 3:


Input: root = [1,1,0,1,1,0,1,0]
Output: [1,1,0,1,1,null,1]
*/

TreeNode* pruneTree(TreeNode* root) {
    if (root == NULL)
        return NULL;
    
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    
    if (!root->left && !root->right && root->val == 0)
        return NULL;
    
    return root;
}

//OR 

bool dfs(TreeNode*& r) {
    if (r == NULL)
        return false;
    
    bool lVal = dfs(r->left);
    bool rVal = dfs(r->right);
    if (!lVal)
        r->left = NULL;
    if (!rVal)
        r->right = NULL;
    return r->val || lVal || rVal;
}

TreeNode* pruneTree(TreeNode* root) {
    return (dfs(root) ? root : NULL);
}

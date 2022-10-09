/*
Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.
*/

int i = 0;
TreeNode* bstFromPreorder(vector<int>& preorder, int mx = INT_MAX) {
    if (i == preorder.size() || preorder[i] >= mx)
        return NULL;

    TreeNode* t = new TreeNode(preorder[i++]);

    t->left = bstFromPreorder(preorder, t->val);
    t->right = bstFromPreorder(preorder, mx);

    return t;
}

// OR

TreeNode* bstFromPreorder(vector<int>& preorder) {
    stack<TreeNode*> s;
    TreeNode* root = new TreeNode(preorder[0]);
    s.push(root);

    for (int i = 1; i < preorder.size(); i++) {
        TreeNode* n = new TreeNode(preorder[i]);
        if (s.top()->val > preorder[i])
            s.top()->left = n;
        else {
            TreeNode* t = NULL;
            while (!s.empty() && s.top()->val < preorder[i]) {
                t = s.top();
                s.pop();
            }
            t->right = n;
        }
        s.push(n);
    }
    return root;
}

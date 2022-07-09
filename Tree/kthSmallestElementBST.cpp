/*
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

Example 1:
Input: root = [3,1,4,null,2], k = 1
Output: 1
*/

int ans = -1;
void preOrder(TreeNode* r, int k, int& i) {
    if (r == NULL)
        return;
    preOrder(r->left, k, i);
    i++;
    if (i == k)
        ans = r->val;
        
    preOrder(r->right, k, i);
}

int kthSmallest(TreeNode* root, int k) {
    int i = 0;
    preOrder(root, k, i);
    return ans;
}

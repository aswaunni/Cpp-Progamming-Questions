/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Example 1:
Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:
Input: root = [1,2,2,null,3,null,3]
Output: false
*/

bool check(TreeNode* r1, TreeNode* r2) {
    if (r1 == NULL && r2 == NULL)
        return true;
    if (r1 == NULL || r2 == NULL || r1->val != r2->val)
        return false;
    return check(r1->left, r2->right) && check(r1->right, r2->left);
}
bool isSymmetric(TreeNode* root) {
    return check(root, root);
}

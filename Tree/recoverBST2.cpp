/*
You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

 

Example 1:


Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
Example 2:


Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
*/

TreeNode* firstElement = NULL;
TreeNode* secondElement = NULL;
TreeNode* prevElement = NULL;

void recoverTree(TreeNode* root) {
    traverse(root);
    
    int t = firstElement->val;
    firstElement->val = secondElement->val;
    secondElement->val = t;
}

void traverse(TreeNode* root) {
    if (!root)
        return;
    
    traverse(root->left);
    
    if (prevElement && prevElement->val >= root->val) {
        if (!firstElement)
            firstElement = prevElement;
        secondElement = root;
    }
    
    prevElement = root;
    
    traverse(root->right);
}

// OR (Iteration)

    void recoverTree(TreeNode* root) {
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = NULL, *cur = root;
    
    stack<TreeNode*> s;
    
    while (!s.empty() || cur) {
        if (cur) {
            s.push(cur);
            cur = cur->left;
        } else {
            cur = s.top();
            s.pop();
            
            if (prev && prev->val >= cur->val) {
                if (!first)
                    first = prev;
                second = cur;
            }
            
            prev = cur;
            cur = cur->right;
        }
    }
    int x = first->val;
    first->val = second->val;
    second->val = x;
}

// OR (Morris Traversal)

    void recoverTree(TreeNode* root) {
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = NULL, *cur = root;
    
    while (cur) {
        if (prev && prev->val >= cur->val) {
            if (!first)
                first = prev;
            second = cur;
        }
        
        if (cur->left) {
            TreeNode* t = cur->left;
            
            while (t->right && t->right != cur)
                t = t->right;
            
            if (!t->right) {
                t->right = cur;
                cur = cur->left;
            } else {
                t->right = NULL;
                prev = cur;
                cur = cur->right;
            }
        } else {
            prev = cur;
            cur = cur->right;
        }
    }
    int x = first->val;
    first->val = second->val;
    second->val = x;
}

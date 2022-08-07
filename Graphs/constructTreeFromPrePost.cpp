/*
Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.

If there exist multiple answers, you can return any of them.

 

Example 1:


Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]
Example 2:

Input: preorder = [1], postorder = [1]
Output: [1]
*/

//Hint : If we meet a same value in the pre and post, it means we complete the construction for current subtree. 
   
TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {     
    vector<TreeNode*> v;
    v.push_back(new TreeNode(pre[0]));
    
    for (int i = 1, j = 0; i < pre.size(); i++) {
        TreeNode* t = new TreeNode(pre[i]);
        
        while (v.back()->val == post[j]) {
            v.pop_back();
            j++;
        }
        
        if (v.back()->left == NULL)
            v.back()->left = t;
        else
            v.back()->right = t;
        
        v.push_back(t);
    }
    return v[0];
}

// OR

int preIdx = 0, postIdx = 0;
TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    TreeNode* root = new TreeNode(pre[preIdx++]);
    
    if (root->val != post[postIdx]) {
        root->left = constructFromPrePost(pre, post);
    if (root->val != post[postIdx])
        root->right = constructFromPrePost(pre, post);
    
    postIdx++;
    return root;
}

/*
Given a binary tree. Check whether it is a BST or not.
Note: We are considering that BSTs can not contain duplicate Nodes.

Example 1:

Input: 2 1 3
Output: 1 

Example 2:

Input: 3 2 5 1 4
Output: 0 (Since 4 is on left side of 3)

*/

bool check(Node* root, int max, int min)
{
	if (!root)
		return true;

	if (root->data < min || root->data > max) 
		return false; 

	return check(root->left, root->data-1, min) && check(root->right, max, root->data+1);
}

bool isBST(Node* root) 
{
	return check(root, INT_MAX, INT_MIN);
}

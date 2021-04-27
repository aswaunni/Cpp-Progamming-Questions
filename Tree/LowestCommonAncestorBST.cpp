/*
   Given a Binary Search Tree (with all values unique) and two node values. Find the Lowest Common Ancestors of the two nodes in the BST.

Example 1:

Input:
    5
  /    \
 4      6
/        \
3          7
 \
  8
n1 = 7, n2 = 8
Output: 7
Example 2:

Input:
  2
 /  \
1    3
n1 = 1, n2 = 3
Output: 2
 */


Node* LCA(Node *root, int n1, int n2)
{
	while(root) {
		if (n1 > root->data && n2 > root->data) {
			root = root->right;
		} else if (n1 < root->data && n2 < root->data) {
			root = root->left;
		} else 
			break;
	}

	return root;
}

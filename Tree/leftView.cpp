/*
   Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.
   Example 1:

Input: 1 3 2
Output: 1 3

Example 2:

Input: 10 20 30 40 60

Output: 10 20 40
 */

void left(Node* root, int level, vector<int>& v)
{
	static int max = 0;

	if (!root)
		return;

	if (max < level) {
		max =  level;
		v.push_back(root->data);
	}    

	if (root->left)
		left(root->left, level+1, v);

	if (root->right)
		left(root->right, level+1, v);
}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
	vector<int> v;
	left(root, 1, v);
	return v;
}

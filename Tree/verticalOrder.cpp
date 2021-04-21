/*
   Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
   If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

Example 1:
Input: 2 N 3 4
Output: 2 4 3

Example 2:
Input: 1 2 3 4 5 N 6
Output: 4 2 1 5 3 6
Your Task:
You don't need to read input or print anything. Your task is to complete the function verticalOrder() which takes the root node as input and returns an array containing the vertical order traversal of the tree from the leftmost to the rightmost level. If 2 nodes lie in the same vertical level, they should be printed in the order they appear in the level order traversal of the tree.
 */

vector<int> verticalOrder(Node *root)
{
	vector<int> result;

	if (!root)
		return result;

	queue<pair<Node*, int>> q;
	map<int, vector<int>> m;
	int hd = 0;

	q.push(make_pair(root, hd));

	while(!q.empty()) {
		pair<Node*, int> a = q.front();
		q.pop();

		hd = a.second;
		Node* n = a.first;

		m[hd].push_back(n->data);

		if (n->left)
			q.push(make_pair(n->left, hd-1));
		if (n->right)
			q.push(make_pair(n->right, hd+1));
	}


	for(auto& a : m) {
		for (auto& b : a.second)
			result.push_back(b);
	}

	return result;
}

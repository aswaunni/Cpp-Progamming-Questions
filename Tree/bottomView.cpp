/*
Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.

Input : 20 8 22 5 3 N 25 N N 10 14

For the above tree, the bottom view is 5 10 3 14 25.

If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

Input : 20 8 22 5 3 4 25 N N 10 N N 14

For the above tree the output should be 5 10 4 14 25.

Solution:
Create a map like, map where key is the horizontal distance and value is a pair(a, b) where a is the value of the node and b is the height of the node. Perform a pre-order traversal of the tree. If the current node at a horizontal distance of h is the first we’ve seen, insert it in the map. Otherwise, compare the node with the existing one in map and if the height of the new node is greater, update in the Map.
 */

void bottom(Node* root, map<int, pair<int, int>>& m, int hd, int level)
{
	if (!root)
		return;

	if (m.find(hd) == m.end()) {
		m[hd] = make_pair(root->data, level);
	} else {
		pair<int, int> p = m[hd];
		if (p.second <= level)
			m[hd] = make_pair(root->data, level);
	}

	bottom(root->left, m, hd-1, level+1);

	bottom(root->right, m, hd+1, level+1);
}

// Method that returns the bottom view.
vector <int> bottomView(Node *root)
{
	map<int, pair<int, int>> m;

	bottom(root, m, 0, 0);

	vector<int> result;
	for (auto& a : m)
		result.push_back(a.second.first);

	return result;
}

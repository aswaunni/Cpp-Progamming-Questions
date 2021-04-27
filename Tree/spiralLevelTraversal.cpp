/*
Complete the function to find spiral order traversal of a tree. For below tree, function should return 1, 2, 3, 4, 5, 6, 7.
Input : 1 2 3 7 6 5 4

*/

vector<int> findSpiral(Node *root)
{
	vector<int> v;

	if (!root)
		return v;

	stack<Node*> s1, s2;

	s1.push(root);

	while (!s1.empty() || !s2.empty()) {
		while (!s1.empty()) {
			Node* n = s1.top();
			v.push_back(n->data);
			s1.pop();

			if (n->left)
				s2.push(n->left);
			if (n->right)
				s2.push(n->right);
		}

		while (!s2.empty()) {
			Node* n = s2.top();
			v.push_back(n->data);
			s2.pop();

			if (n->right)
				s1.push(n->right);
			if (n->left)
				s1.push(n->left);            
		}
	}

	return v;
}

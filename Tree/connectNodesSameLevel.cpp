/*
   Given a binary tree, connect the nodes that are at same level. You'll be given an addition nextRight pointer for the same.

   Initially, all the nextRight pointers point to garbage values. Your function should set these pointers to point next right for each node.
   10                    10 ------> NULL
   / \                 /   \
  3   5       =>     3 ---> 5 --------> NULL
 / \   \           /  \      \
4   1   2         4 --> 1 --> 2 -------> NULL



Example 1:

Input:
   3
 /  \
1    2
Output:
3 1 2
1 3 2
Explanation:The connected tree is
  3 ------> NULL
 /  \
1---> 2 ------ NULL
 */

//Method 1
void connect(Node *root)
{
	if (!root)
		return;

	queue<Node*> q;

	q.push(root);
	q.push(NULL);

	while (!q.empty()) {
		Node* f = q.front();
		q.pop();

		if (f) {
			f->nextRight = q.front();

			if (f->left)
				q.push(f->left);
			if (f->right)
				q.push(f->right);   
		} else if (!q.empty())
			q.push(NULL);

	}
	return;
}    

//Method 2
void connect(Node *root)
{
	if (!root)
		return;

	queue<Node*> q1, q2;

	q1.push(root);

	while(!q1.empty() || !q2.empty()) {
		while (!q1.empty()) {
			Node* f = q1.front();
			q1.pop();

			if(q1.empty())
				f->nextRight = NULL;
			else
				f->nextRight = q1.front();

			if (f->left)
				q2.push(f->left);
			if (f->right)
				q2.push(f->right);
		}
		while (!q2.empty()) {
			Node* f = q2.front();
			q2.pop();

			if(q2.empty())
				f->nextRight = NULL;
			else
				f->nextRight = q2.front();

			if (f->left)
				q1.push(f->left);
			if (f->right)
				q1.push(f->right);
		}
	}
	return;
}

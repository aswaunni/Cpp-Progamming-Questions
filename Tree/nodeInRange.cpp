/*
Given a Binary Search Tree (BST) and a range l-h(inclusive), count the number of nodes in the BST that lie in the given range.

The values smaller than root go to the left side
The values greater and equal to the root go to the right side
Example 1:

Input:
      10
     /  \
    5    50
   /    /  \
  1    40  100
l = 5, h = 45
Output: 3
Explanation: 5 10 40 are the node in the
range
Example 2:

Input:
     5
    /  \
   4    6
  /      \
 3        7
l = 2, h = 8
Output: 5
Explanation: All the nodes are in the
given range.
*/

int getCount(Node *root, int l, int h)
{
    if (root == NULL)
        return 0;
    if (root->data <= h && root->data >= l)
        return 1 + getCount(root->left, l, h) + getCount(root->right, l, h);
    if (root->data < l)
        return getCount(root->right, l, h);
    if (root->data > h)
        return getCount(root->left, l, h);
}

//OR

void getCount(Node *root, int l, int h, int& count)
{
    if (root == NULL)
        return;
    
    if (root->data <= h && root->data >= l)
        ++count;
    getCount(root->right, l, h, count);
    getCount(root->left, l, h, count);
}

int getCount(Node *root, int l, int h)
{
    int count = 0;
    getCount(root, l, h, count);
    return count;
}

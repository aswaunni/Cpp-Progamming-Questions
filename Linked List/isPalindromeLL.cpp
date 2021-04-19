/*
Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

Example 1:

Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1.
Example 2:

Input:
N = 4
value[] = {1,2,3,4}
Output: 0
Explanation: The given linked list
is 1 2 3 4 , which is not a palindrome
and Hence, the output is 0.

METHOD 1 (Use a Stack) 


A simple solution is to use a stack of list nodes. This mainly involves three steps.
Traverse the given list from head to tail and push every visited node to stack.
Traverse the list again. For every visited node, pop a node from stack and compare data of popped node with currently visited node.
If all nodes matched, then return true, else false.
*/

#include <bits/stdc++.h>
using namespace std;

struct node {
	node* next;
	int data;
	node(int d) 
	{
		data = d;
		next = NULL;
	}
};

struct linkedList {
	node* head;

	linkedList()
	{
		head = NULL;
	}

	void push(int d)
	{
		node* n = new node(d);
		n->data = d;
		n->next = head;
		head = n;
	}

	void print()
	{
		node* n = head;
		while(n != NULL) {
			cout << n->data << " ";
			n = n->next;
		}
		cout << "\n";
	}

	void middle()
	{
		node* one = head, *two = head;
		while(two && two->next) {
			one = one->next;
			two = two->next->next;
		}
		cout << two->data << "\n";
	}
};

void print(node* n)
{
	while(n != NULL) {
		cout << n->data << " ";
		n = n->next;
	}
	cout << "\n";
}

bool isPalindrome(node *head)
{
	stack<int> s;
	node* cur = head;

	while(cur) {
		s.push(cur->data);
		cur = cur->next;
	}

	cur = head;

	while(cur) {
		if (cur->data != s.top())
			return false;
		cur = cur->next;
		s.pop();
	}
	return true;
}

int main() {
	linkedList l1;
	l1.push(1);
	l1.push(3);
	l1.push(6);
	l1.push(3);
	l1.push(1);
	l1.print();

	cout << "Is palindrome : " << isPalindrome(l1.head);

	return 0;
}



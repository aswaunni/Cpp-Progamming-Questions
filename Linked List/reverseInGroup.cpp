/*
Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list.

Example 1:

Input:
LinkedList: 1->2->2->4->5->6->7->8
K = 4
Output: 4 2 2 1 8 7 6 5 
Explanation: 
The first 4 elements 1,2,2,4 are reversed first 
and then the next 4 elements 5,6,7,8. Hence, the 
resultant linked list is 4->2->2->1->8->7->6->5.


 we have used a stack which will store the nodes of the given linked list. Firstly, push the k elements of the linked list in the stack. Now pop elements one by one and keep track of the previously popped node. Point the next pointer of prev node to top element of stack. Repeat this process, until NULL is reached.
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

node* groupReverse(node* head, int k)  
{   
	node* cur = head, *prev = NULL;
	stack<node*> s;
	while (cur) {
		int count = 0;

		while (cur && count < k) {
			s.push(cur);
			cur = cur->next;
			count++;
		}

		while(s.size() > 0) {
			if(!prev) {
				prev = s.top();
				head = prev;
				s.pop();
			} else {
				prev->next = s.top();
				prev = prev->next;
				s.pop();
			}
		}
	}

	prev->next = NULL;

	return head;
}

int main() {
	linkedList ll;
	l1.push(8);
	l1.push(7);
	l1.push(6);
	l1.push(5);
	l1.push(4);
	l1.push(2);
	l1.push(2);
	l1.push(1);
	l1.print();


	node* n = groupReverse(l1.head, 4);
	print(n);

	return 0;
}



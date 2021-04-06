/*
Given a singly linked list of size N. The task is to rotate the linked list counter-clockwise by k nodes, where k is a given positive integer smaller than or equal to length of the linked list.

Example 1:

Input:
N = 8
value[] = {1,2,3,4,5,6,7,8}
k = 4
Output: 5 6 7 8 1 2 3 4
Explanation:
Example 2:

Input:
N = 5
value[] = {2,4,7,8,9}
k = 3
Output: 8 9 2 4 7
Explanation:
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
		while(two) {
			if (two->next) {
				one = one->next;
				if (two->next->next)
					two = two->next->next;
				else
					break;
			} else
				break;
		}
		cout << one->data << "\n";
	}

	void rotate(int k)
	{
		node* curr = head;
		int count = 0;
		node* newHead = NULL, *newTail = NULL;

		while (curr->next != NULL) {            
			count++;
			if (count == k) {
				newTail = curr;
				newHead = curr->next;
			}
			curr = curr->next;
		}

		if (newHead) {
			curr->next = head;
			head = newHead;
			newTail->next = NULL;
		}
	}
};

int main() {
	linkedList ll;
	ll.push(8);
	ll.push(7);
	ll.push(6);
	ll.push(5);
	ll.push(4);
	ll.push(3);
	ll.push(2);
	ll.push(1);

	ll.print();

	ll.rotate(8);

	ll.print();

	return 0;
}

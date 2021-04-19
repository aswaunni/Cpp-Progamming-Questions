/*
Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.

Example 1:

Input:
N = 8
value[] = {1,2,2,1,2,0,2,2}
Output: 0 1 1 2 2 2 2 2
Explanation: All the 0s are segregated
to the left end of the linked list,
2s to the right end of the list, and
1s in between.

Traverse the list and count the number of 0s, 1s and 2s. Let the counts be n1, n2 and n3 respectively.
Traverse the list again, fill the first n1 nodes with 0, then n2 nodes with 1 and finally n3 nodes with 2.
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

node* segregate(node *head) {
	if (!head || head->next == NULL)
		return head;

	node* cur = head;
	int arr[3] = {0};

	while(cur) {
		arr[cur->data]++;
		cur = cur->next;
	}

	cur = head;
	for (int i = 0; i < 3; ) {
		if (arr[i] == 0)
			i++;
		else {
			cur->data = i;
			arr[i]--;
			cur = cur->next;
		}
	}
	return head; 
}

int main() {
	linkedList l1;
	l1.push(1);
	l1.push(0);
	l1.push(0);
	l1.push(1);
	l1.push(2);
	l1.print();

	node* n = segregate(l1.head);

	print(n);

	return 0;
}



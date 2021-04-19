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

node* pairWiseSwap(node* head) 
{

	if (head == NULL || head->next == NULL)
		return head;

	node* cur = head->next, *prev = head, *next = NULL;

	head = cur;

	while(cur) {
		next = cur->next;
		cur->next = prev;

		if (next == NULL || next->next == NULL) {
			prev->next = next;
			break;
		}

		prev->next = next->next;

		prev = next;
		cur = prev->next;
	}
	return head;
}

int main() {
	linkedList l1;
	l1.push(8);
	l1.push(7);
	l1.push(6);
	l1.push(5);
	l1.push(4);
	l1.push(2);
	l1.push(2);
	l1.push(1);
	l1.print();

	node* head  = pairWiseSwap(l1.head);
	print(head);

	return 0;
}



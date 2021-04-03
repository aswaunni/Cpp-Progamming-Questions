#include <bits/stdc++.h>

using namespace std;


struct node {
	int data;
	struct node* next;
	node(int d) 
	{
		data = d;
		next = NULL;
	}
	node() 
	{
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
		node* temp = new node(d);
		temp->next = head;
		head = temp;
	}

	void print()
	{
		node* temp = head;
		while(temp) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << "\n";
	}

	void merge(linkedList& l1, linkedList& l2)
	{
		node* c1 = l1.head, *c2 = l2.head;
		node* prev = NULL;
		while (c1 || c2) {
			int int1 = (c1 == NULL ? INT_MAX : c1->data);
			int int2 = (c2 == NULL ? INT_MAX : c2->data);
			node* r;
			if (int1 < int2) {
				r = new node(int1);
				c1 = (c1 == NULL ? NULL : c1->next);
			} else {
				r = new node(int2);
				c2 = (c2 == NULL ? NULL : c2->next);
			}
			if (prev)
				prev->next = r;
			if (!head)
				head = r;
			prev = r;
		}
	}
};

int main() {

	linkedList l1, l2;
	l1.push(19);
	l1.push(15);
	l1.push(8);
	l1.push(4);
	l1.print();
	l2.push(16);
	l2.push(10);
	l2.push(9);
	l2.push(7);
	l2.print();

	linkedList l3;
	l3.merge(l1, l2);
	l3.print();

	return 0;
}



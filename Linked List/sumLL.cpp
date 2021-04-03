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

	void add(linkedList& l1, linkedList& l2)
	{
		int carry = 0;
		node* c1 = l1.head, *c2 = l2.head;
		node* prev = NULL;

		while (c1 || c2 || carry>0) {
			int int1 = (c1 == NULL ? 0 : c1->data);
			int int2 = (c2 == NULL ? 0 : c2->data);

			int sum = int1 + int2 + carry;
			node* r = new node(sum%10);
			carry = sum/10;
			if (!head)
				head = r;
			if (prev)
				prev->next = r;
			prev = r;
			c1 = (c1 == NULL ? NULL : c1->next);;
			c2 = (c2 == NULL ? NULL : c2->next);;
		}
	}
};

int main() {

	linkedList l1, l2;
	l1.push(9);
	l1.push(9);
	l1.push(0);
	l1.push(1);
	l1.print();
	l2.push(2);
	l2.push(3);
	l2.push(7);
	l2.print();

	linkedList l3;
	l3.add(l1, l2);
	l3.print();

	return 0;
}

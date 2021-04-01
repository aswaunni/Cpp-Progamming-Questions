#include <bits/stdc++.h>

using namespace std;


struct node {
	int data;
	node* next;
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

	void reverse()
	{
		node* curr = head, *prev = NULL, *next = NULL;
		while (curr) {	
			next = curr->next;
			curr->next = prev;		
			prev = curr;
			curr = next;
		}
		head = prev;
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
};

int main() {

	linkedList ll;
	ll.push(1);
	ll.push(2);
	ll.push(3);
	ll.print();
	ll.reverse();
	ll.print();

	return 0;
}

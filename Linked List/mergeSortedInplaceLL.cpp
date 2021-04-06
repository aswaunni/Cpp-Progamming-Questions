/*
Given two sorted linked lists consisting of N and M nodes respectively. The task is to merge both of the list (in-place) and return head of the merged list.
 

 Example 1:

 Input:
 N = 4, M = 3 
 valueN[] = {5,10,15,40}
 valueM[] = {2,3,20}
 Output: 2 3 5 10 15 20 40
 Explanation: After merging the two linked
 lists, we have merged list as 2, 3, 5,
 10, 15, 20, 40.
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
};

void print(node* n)
{
	while(n != NULL) {
		cout << n->data << " ";
		n = n->next;
	}
	cout << "\n";
}

node* sortedMerge(node* head1, node* head2)  
{   
	node* cur1 = head1, *cur2 = head2;
	node* tail1 = NULL, *tail2 = NULL;
	node* newHead = (cur1->data <= cur2->data ? head1 : head2);
	while (cur1 && cur2) {
		if (cur1->data <= cur2->data){
			while(cur1->next && cur1->next->data <= cur2->data) {
				cur1 = cur1->next;
			} 
			tail1 = cur1->next;
			cur1->next = cur2;
			cur1 = tail1;
		} else {
			while(cur2->next && cur1->data > cur2->next->data) {
				cur2 = cur2->next;
			}
			tail2 = cur2->next;
			cur2->next = cur1;
			cur2 = tail2;
		}
	}
	return newHead;
}

int main() {
	linkedList l1;
	l1.push(25);
	l1.push(12);
	l1.push(10);
	l1.push(5);
	l1.print();

	linkedList l2;
	l2.push(20);
	l2.push(10);
	l2.push(2);
	l2.print();

	node* n = sortedMerge(l1.head, l2.head);
	print(n);

	return 0;
}




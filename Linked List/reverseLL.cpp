#include <bits/stdc++.h>

using namespace std;


class Node {
public:
    Node(int i) {
        data = i;
        next = NULL;    
    }
    Node(int i, Node* n) {
        data = i;
        next = n;    
    }
    Node* next;
    int data;
};

void printLL(Node* head) {
    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* reverseLL(Node* head) {
    Node* cur = head, *prev = NULL;

    while(cur) {
        Node* temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
}

Node* reverseLLRecusive(Node* head) {
    if (head == NULL || (head->next == NULL))
        return head;
    Node* newHead = reverseLLRecusive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;   
}
   
int main()
{
    Node* a = new Node(3);
    Node* b = new Node(2, a);
    Node* c = new Node(1, b);
    Node* head = c;

    printLL(head);
    head = reverseLLRecusive(head);
    printLL(head);

    return 0;
}

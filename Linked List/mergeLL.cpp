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

void insertLL(Node* &head, int i) {
    Node* temp = head;
    Node* n = new Node(i);
    
    if(head == NULL)
        head = n;
    while(temp->next)
        temp = temp->next;
    temp->next = n;
}

void printLL(Node* head) {
    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* mergeLL(Node* h1, Node* h2){
    Node* dummy = new Node(-1);
    Node* newHead = dummy;
    while(h1 && h2) {
        if (h1->data < h2->data) {
            dummy->next = h1;
            h1 = h1->next;
            dummy = dummy->next;
        } else {
            dummy->next = h2;
            h2 = h2->next;
            dummy = dummy->next;
        }
    }

    while(h1) {
        dummy->next = h1;
        h1 = h1->next;
        dummy = dummy->next;
    }

    while (h2) {
        dummy->next = h2;
        h2 = h2->next;
        dummy = dummy->next;
    }
    return newHead->next;
}

Node* mergeLLRecursive(Node* h1, Node* h2) {
    if (h1 == NULL) 
        return h2;

    if (h2 == NULL)
        return h1;
    
    Node* result;
    if (h1->data < h2->data) {
        result = h1;
        result->next = mergeLLRecursive(h1->next, h2);
    } else {
        result = h2;
        result->next = mergeLLRecursive(h1, h2->next);
    }
    return result;
}

int main()
{
    Node* l1 = new Node(1);
    insertLL(l1, 4);
    insertLL(l1, 5);
    insertLL(l1, 7);
    Node* l2 = new Node(2);
    insertLL(l2, 3);
    insertLL(l2, 6);

    printLL(l1);
    printLL(l2);

    printLL(mergeLLRecursive(l1, l2));

    return 0;
}

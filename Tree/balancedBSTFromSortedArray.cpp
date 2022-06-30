#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node* left;
    Node* right;
    int data;
    
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* balancedBSTFromSortedArray(int arr[], int s, int e) {
    if (s > e)
        return NULL;
    
    int mid = (s+e)/2;
    Node* root = new Node(arr[mid]);
    root->left = balancedBSTFromSortedArray(arr, s, mid-1);
    root->right = balancedBSTFromSortedArray(arr, mid+1, e);
    return root;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    Node* root = balancedBSTFromSortedArray(arr, 0, 4);
    
    return 0;
}

/*
Given a set of arrays of size n and an integer k, you have to find the maximum integer for each and every contiguous subarray of size k for each of the given arrays.

Input Format

First line of input will contain the number of test cases T. For each test case, you will be given the size of array N and the size of subarray to be used K. This will be followed by the elements of the array Ai.

Output Format

For each of the contiguous subarrays of size  of each array, you have to print the maximum integer.

*/

#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
	deque<int> d;
    
    for (int i = 0; i < n; i++) {
        while (!d.empty() && arr[i] > d.back())
            d.pop_back();
            
        d.push_back(arr[i]);
        
        if ((i+1) >= k) {
            cout << d.front() << " ";
            if (arr[i+1-k] == d.front())
                d.pop_front();
        }
    }
    cout << "\n";
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}

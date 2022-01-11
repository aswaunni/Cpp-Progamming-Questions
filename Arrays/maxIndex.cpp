/*
Given an array A[] of N positive integers. The task is to find the maximum of j - i subjected to the constraint of A[i] < A[j] and i < j.
 

Example 1:

Input:
N = 2
A[] = {1, 10}
Output:
1
Explanation:
A[0]<A[1] so (j-i) is 1-0 = 1.
Example 2:

Input:
N = 9
A[] = {34, 8, 10, 3, 2, 80, 30, 33, 1}
Output:
6
Explanation:
In the given array A[1] < A[7]
satisfying the required 
condition(A[i] < A[j]) thus giving 
the maximum difference of j - i 
which is 6(7-1).

*/

int maxIndexDiff(int a[], int n) 
{ 
    multimap<int, int> m;
    
    for (int i = 0; i < n; i++)
        m.insert(pair<int, int>(a[i], i));
    
    int x = m.begin()->second;
    int ans = 0;
    for (auto& a : m) {
        if (x <= a.second)
            ans = max(ans, a.second - x);
        else
            x = a.second;
    }
    return ans;
}

//OR

int maxIndexDiff(int a[], int n) 
{ 
    int i = 0, j = n-1;
    int ans = 0;
    
    while (i <= j) {
        if (a[i] <= a[j]) {
            ans = max(ans, j-i);
            i++;
            j = n-1;
        } else
            j--;
    }
    return ans;
}

//OR

int maxIndexDiff(int A[], int N) 
{ 
    vector<int> rMax(N);
    rMax[N-1] = A[N-1];
    for (int i = N-2; i >=0 ; i--) 
        rMax[i] = max(rMax[i+1], A[i]);
    
    int ans = INT_MIN;
    int i = 0, j = 0;
    while (i < N && j < N) {
        if (rMax[j] >= A[i]) {
            ans = max(ans, j-i);
            j++;
        } else
            i++;
    }
    return ans;
}

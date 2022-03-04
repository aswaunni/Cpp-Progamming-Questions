/*
Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
 

Example 1:

Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).
*/

long long int inversionCount(long long arr[], long long N)
{
    long long ans = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (arr[i] > arr[j])
                ans++;
        }
    }
    return ans;
}

//OR 

    long long merge(long long arr[], int l, int r, int mid)
    {
        long long i = l, j = mid+1, cur = 0;
        long long ans = 0;
        vector<long long > temp;
        
        while (i <= mid && j <= r) {
            if (arr[i] <= arr[j])
                temp.push_back(arr[i++]);
            else {
                temp.push_back(arr[j++]);
                ans += mid - i + 1;
            }
        }
        
        while (i <= mid)
            temp.push_back(arr[i++]);
        while (j <= r)
            temp.push_back(arr[j++]);
            
        for(int i = l; i <= r; i++)
           arr[i] = temp[cur++];

       return ans;
    }

    long long solve(long long arr[], int l, int r) 
    {
        if (l >= r)
            return 0;
            
        int mid = (l + r)/2;
        return solve(arr, l, mid) + solve(arr, mid+1, r) + merge(arr, l, r, mid);

    }

    long long int inversionCount(long long arr[], long long N)
    {
        return solve(arr, 0, N-1);
    }

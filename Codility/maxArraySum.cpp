/*

Given an array of integers, find the subset of non-adjacent elements with the maximum sum. Calculate the sum of that subset. It is possible that the maximum sum is 0, the case when all elements are negative.

Example
arr = {-2, 1, 3, -4, 5}
The following subsets with more than 1 element exist. These exclude the empty subset and single element subsets which are also valid.

Subset      Sum
[-2, 3, 5]   6
[-2, 3]      1
[-2, -4]    -6
[-2, 5]      3
[1, -4]     -3
[1, 5]       6
[3, 5]       8
The maximum subset sum is 8. Note that any individual element is a subset as well.
arr = {-2, -3, -1}

In this case, it is best to choose no element: return 0.

Function Description

Complete the maxSubsetSum function in the editor below.

maxSubsetSum has the following parameter(s):

int arr[n]: an array of integers
Returns
- int: the maximum subset sum

Input Format

The first line contains an integer, n.
The second line contains n space-separated integers arr[i] .

Constraints

Sample Input 0

5
3 7 4 6 5
Sample Output 0

13
*/

int maxSubsetSum(vector<int> arr) {
    int dp[100005];
    dp[0]=max(0,arr[0]);
    if(arr.size()==1)
        return dp[0];
    for(int i=1;i<arr.size();i++)
    {
        dp[i]=max(dp[i-2],max(dp[i-1],dp[i-2]+arr[i]));
    }
    int n=arr.size();
    return max(dp[n-1],dp[n-2]);

}

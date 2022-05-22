/*
----------------------------------
KADANE'S ALGORITHM 
----------------------------------

Used to find maximum sub-array Sum.
The simple idea of Kadane’s algorithm is to look for all positive contiguous segments of the array (max_ending_here is used for this). 
And keep track of maximum sum contiguous segment among all positive segments (max_so_far is used for this). 
Each time we get a positive sum compare it with max_so_far and update max_so_far if it is greater than max_so_far
*/

long long maxSubarraySum(int arr[], int n){
        int maxHere = arr[0];
        int ans = arr[0];
        
        for (int i = 1; i < n; i++) {
            maxHere = max(maxHere+arr[i], arr[i]);
            ans = max(ans, maxHere);
        }
	
        return ans;
}

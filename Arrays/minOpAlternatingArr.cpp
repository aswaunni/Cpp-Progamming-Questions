/*
You are given a 0-indexed array nums consisting of n positive integers.

The array nums is called alternating if:

nums[i - 2] == nums[i], where 2 <= i <= n - 1.
nums[i - 1] != nums[i], where 1 <= i <= n - 1.
In one operation, you can choose an index i and change nums[i] into any positive integer.

Return the minimum number of operations required to make the array alternating.

 

Example 1:

Input: nums = [3,1,3,2,4,3]
Output: 3
Explanation:
One way to make the array alternating is by converting it to [3,1,3,1,3,1].
The number of operations required in this case is 3.
It can be proven that it is not possible to make the array alternating in less than 3 operations. 
Example 2:

Input: nums = [1,2,2,2,2]
Output: 2
Explanation:
One way to make the array alternating is by converting it to [1,2,1,2,1].
The number of operations required in this case is 2.
Note that the array cannot be converted to [2,2,2,2,2] because in this case nums[0] == nums[1] which violates the conditions of an alternating array.
*/

int minimumOperations(vector<int>& nums) {
    int freq[100005][2];
    memset(freq, 0, sizeof(freq));
    int n=nums.size(), i, j, k, ans=0;
    for(i = 0; i < n; i++) {
		freq[nums[i]][i&1]++;
	}
    for(i = 1, j = k = 0; i <= 100000; i++) {
        ans = max(ans, max(freq[i][0] + k, freq[i][1] + j));
        j = max(j, freq[i][0]);
        k = max(k, freq[i][1]);
    }
    return n - ans;
}

// OR

array<int, 3> top2Freq(vector<int>& v, int idx) {
    int first, second;
    int n = v.size();
    map<int, int> m;
    
    for (int i = idx; i < n; i += 2) {
        m[v[i]]++;
        if (m[v[i]] >= m[first]) {
            if (v[i] != first)
                second = first;
            first = v[i];
        } else if (m[v[i]] > m[second])
            second = v[i];
    }
    return {first, m[first], m[second]};
    
}
int minimumOperations(vector<int>& nums) {
    auto ev = top2Freq(nums, 0), od = top2Freq(nums, 1);
    return nums.size() - (ev[0] != od[0] ? ev[1] + od[1] : max(ev[1] + od[2], ev[2] + od[1]));        
}

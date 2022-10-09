/*
Given an integer array nums, return the number of longest increasing subsequences.

Notice that the sequence has to be strictly increasing.

 

Example 1:

Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:

Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.
 

Constraints:

1 <= nums.length <= 2000
-106 <= nums[i] <= 106
*/

int findNumberOfLIS(vector<int>& nums) {
    int mxLen = 1, ans = 1;
    int n = nums.size();
    vector<int> len(n, 1), cnt(n, 1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                if (len[j]+1 == len[i])
                    cnt[i] += cnt[j];
                else if (len[j]+1 > len[i]) {
                    len[i] = len[j]+1;
                    cnt[i] = cnt[j];
                }
            }
        }

        if (mxLen == len[i])
            ans += cnt[i];
        if (mxLen < len[i]) {
            mxLen = len[i];
            ans = cnt[i];
        }
    }
    return ans;
}

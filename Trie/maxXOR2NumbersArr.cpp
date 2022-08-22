/*
Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

 

Example 1:

Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.
Example 2:

Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127
*/

class Solution {
public:
    class TrieNode {
        TrieNode* child[2] = {};
    
    public:
        void build(int n) {
            TrieNode* cur = this;
            for (int i = 31; i >= 0; i--) {
                int bit = (n >> i) & 1;
                if (!cur->child[bit])
                    cur->child[bit] = new TrieNode();
                
                cur = cur->child[bit];
            }
        }
        
        int findMax(int n) {
            TrieNode* cur = this;
            int ans = 0;
            
            for (int i = 31; i >= 0; i--) {
                int bit = (n >> i) & 1;
                if (!cur->child[1-bit])
                    cur = cur->child[bit];
                else {
                    ans |= (1 << i);
                    cur = cur->child[1-bit];
                }
            }
            return ans;
        }
    };
    
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* trie = new TrieNode();
        for (int& a : nums)
            trie->build(a);
        
        int ans = 0;
        for (int& a : nums)
            ans = max(ans, trie->findMax(a));
        return ans;
    }
};

/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
*/

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<vector<int>,vector<string>> mpp;
    
    for(int i=0; i<strs.size(); i++){
        vector<int> v(26,0); 
        
        for(int j=0; j<strs[i].size(); j++){
            v[strs[i][j] - 'a']++; 
        }
        
        mpp[v].push_back(strs[i]);
    }
    
    vector<vector<string>> ans;
    for(auto it: mpp){
        ans.push_back(it.second); 
    }
    
    return ans;
}

// OR

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string,vector<string>> mp;
    vector<vector<string>> ans;
    for(auto &x:strs){
        string s="00000000000000000000000000";
        for(auto &y:x){
            s[y-'a']++;
        }
        mp[s].push_back(x);
    }
    for(auto &x:mp){
        ans.push_back(x.second);
    }
    return ans;
    
}

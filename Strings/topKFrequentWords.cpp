/*
Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

 

Example 1:

Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:

Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
*/

vector<string> topKFrequent(vector<string>& words, int k) {
    map<string, int> m;
    
    for (auto& a : words)
        m[a]++;
    
    vector<vector<string>> vs(words.size()+1);
    for (auto& [a, b] : m)
        vs[b].push_back(a);
    
    vector<string> ans;
    for (int i = vs.size() - 1; i >= 0 && ans.size() < k; i--) {
        for (auto& c : vs[i]) {
            ans.push_back(c);
            if (ans.size() == k)
                break;
        }
    }
    return ans;
}

// OR

typedef pair<int, string> psi;

struct comp {
    bool operator () (const psi a, const psi b) {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    }    
};

vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> m;
    
    for (auto& a : words)
        m[a]++;
    
    priority_queue<psi, vector<psi>, comp> pq;
    
    for (auto& [a, b] : m) {
        pq.push({b, a});
        if (pq.size() > k)
            pq.pop();
    }
    
    vector<string> ans(k);
    while (k--) {
        ans[k] = pq.top().second;
        pq.pop();
    }
    return ans;
}

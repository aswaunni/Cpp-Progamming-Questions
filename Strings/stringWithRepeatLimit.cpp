/*
You are given a string s and an integer repeatLimit. Construct a new string repeatLimitedString using the characters of s such that no letter appears more than repeatLimit times in a row. You do not have to use all characters from s.

Return the lexicographically largest repeatLimitedString possible.

A string a is lexicographically larger than a string b if in the first position where a and b differ, string a has a letter that appears later in the alphabet than the corresponding letter in b. If the first min(a.length, b.length) characters do not differ, then the longer string is the lexicographically larger one.
*/

string repeatLimitedString(string s, int repeatLimit) {
    vector<int> v(26, 0);
    string ans;
    
    for (auto& a : s)
        v[a - 'a']++;
    
    priority_queue<pair<char, int>> q;
    for (int i = 0; i < 26; i++) {
        if (v[i] > 0)
            q.push({'a' + i, v[i]});
    }
    
    while(!q.empty()) {
        auto [key, count] = q.top();
        q.pop();
        
        for (int i = 0; i < repeatLimit && count > 0; i++) {
            ans += key;
            count--;
        }
        
        if (count > 0 && !q.empty()) {
            auto [secondKey, secondCount] = q.top();
            q.pop();
            
            ans += secondKey;
            if (secondCount > 1)
                q.push({secondKey, secondCount - 1});
            
            q.push({key, count});
        }
        
    }
    return ans;
}

// OR

string repeatLimitedString(string s, int repeatLimit) {
    vector<int> v(26, 0);
    string ans;
    
    for (auto& a : s)
        v[a - 'a']++;
    
    int prevIdx = -1, prevCnt = 0;
    
    while (true) {
        int i = 25;
        
        while (i >= 0 && (v[i] == 0 || (prevCnt == repeatLimit && prevIdx == i))) i--;
               
        if (i >= 0) {
            ans += ('a' + i);
            prevCnt = (prevIdx == i ? prevCnt+1 : 1);
            prevIdx = i;
            v[i]--;
        } else
            break;
    }
    return ans;
}

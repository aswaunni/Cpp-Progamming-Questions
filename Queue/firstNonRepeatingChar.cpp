/*
Given an input stream of A of n characters consisting only of lower case alphabets. The task is to find the first non repeating character, each time a character is inserted to the stream. If there is no such character then append '#' to the answer.
 

 Example 1:

 Input: A = "aabc"
 Output: "a#bb"
 Explanation: For every character first non
 repeating character is as follow-
 "a" - first non-repeating character is 'a'
 "aa" - no non-repeating character so '#'
 "aab" - first non-repeating character is 'b'
 "aabc" - first non-repeating character is 'b'
*/

string FirstNonRepeating(string a){
    vector<int> freq(26, 0);
    queue<char> q;
    string ans;
    
    for (int i = 0; i < a.length(); i++) {
        q.push(a[i]);
        freq[a[i] -'a']++;
        while(!q.empty() && freq[q.front()-'a'] > 1) q.pop();
        
        ans += (q.empty() ? '#' : q.front());
    }
    return ans;
}

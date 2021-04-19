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

// { Driver Code Starts
#include<bits/stdc++.h>
	using namespace std;

	// } Driver Code Ends
	class Solution {
		public:
			string FirstNonRepeating(string str){
				queue<char> q;
				int charCount[26] = { 0 };


				for (int i = 0; str[i]; i++) {

					q.push(str[i]);
					charCount[str[i] - 'a']++;

					while (!q.empty()) {
						if (charCount[q.front() - 'a'] > 1)
							q.pop();
						else {
							str[i] = q.front();
							break;
						}
					} 
					if (q.empty())
						str[i] = '#';
				}
				return str;
			}

	};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends

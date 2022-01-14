/*
Given a dictionary of distinct words and an M x N board where every cell has one character. Find all possible words from the dictionary that can be formed by a sequence of adjacent characters on the board. We can move to any of 8 adjacent characters

Note: While forming a word we can move to any of the 8 adjacent cells. A cell can be used only once in one word.


Example 1:

Input: 
N = 1
dictionary = {"CAT"}
R = 3, C = 3
board = {{C,A,P},{A,N,D},{T,I,E}}
Output:
CAT
Explanation: 
C A P
A N D
T I E
Words we got is denoted using same color.
Example 2:

Input:
N = 4
dictionary = {"GEEKS","FOR","QUIZ","GO"}
R = 3, C = 3 
board = {{G,I,Z},{U,E,K},{Q,S,E}}
Output:
GEEKS QUIZ
Explanation: 
G I Z
U E K
Q S E 
Words we got is denoted using same color.

Your task:
You don’t need to read input or print anything. Your task is to complete the function wordBoggle() which takes the dictionary contaning N space-separated strings and R*C board as input parameters and returns a list of words that exist on the board in lexicographical order.


Expected Time Complexity: O(N*W + R*C^2)
Expected Auxiliary Space: O(N*W + R*C)


Constraints:
1 ≤ N ≤ 15
1 ≤ R, C ≤ 50
1 ≤ length of Word ≤ 60
Each word can consist of both lowercase and uppercase letters.
*/

 bool solve (string word, int idx, vector<vector<char> >& board, int i, int j, int m, int n, std::vector<std::vector<bool>>& visited) 
 {
     if (idx == word.length())
         return true;
     
     if (i >= 0 && i < m && j < n && j >= 0 && !visited[i][j] && word[idx] == board[i][j]) {
         visited[i][j] = true;    
         for (int row = i - 1; row <= i + 1 && row < m; row++)
             for (int col = j - 1; col <= j + 1 && col < n; col++)
                 if (solve(word, idx+1, board, row, col, m, n, visited))
                     return true;
         visited[i][j] = false;  
     }
     return false;
 }   
    
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    vector<string> ans;
	    int m = board.size();
	    int n = board[0].size();
	    for (auto& word : dictionary) {
	        bool flag = false;
	        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
            for (int i = 0; i < m && !flag; i++) {
                for ( int j = 0; j < n; j++) {
	                if (word[0] == board[i][j] && solve (word, 0, board, i, j, m, n, visited)) {
                        ans.push_back(word);
                        flag = true;
                        break;
	                }
                }
            }
	    }
	    return ans;
	}

/*
Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
 

 Example 1:

 Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
 Output: 1
 Explanation: The grid is-
 0 1 2
 0 1 2
 2 1 1
 Oranges at positions (0,2), (1,2), (2,0)
 will rot oranges at (0,1), (1,1), (2,2) and 
 (2,1) in unit time.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		struct ele {
			int x;
			int y;
		};

		bool isDelimiter(ele n)
		{
			return (n.x == -1 && n.y == -1);
		}

		bool isValid(int i, int j, int R, int C)
		{
			return (i >= 0 && j >=0 && i < R && j < C);
		}

		bool checkAll(vector<vector<int>>& grid)
		{
			int R = grid.size(), C = grid[0].size();

			for (int i = 0; i < grid.size(); i++) {
				for (int j = 0; j < grid[0].size(); j++) {
					if (grid[i][j] == 1) {
						return false;
					}
				}
			}
			return true;
		}

		int orangesRotting(vector<vector<int>>& grid) {
			queue<ele> Q;
			ele temp;
			int ans = 0;

			int R = grid.size(), C = grid[0].size();

			for (int i = 0; i < grid.size(); i++) {
				for (int j = 0; j < grid[0].size(); j++) {
					if (grid[i][j] == 2) {
						temp.x = i;
						temp.y = j;
						Q.push(temp);
					}
				}
			}

			temp.x = -1;
			temp.y = -1;
			Q.push(temp);

			while (!Q.empty()) {
				bool flag = false;
				while(!isDelimiter(Q.front())) {
					temp = Q.front();

					if (isValid(temp.x+1, temp.y, R, C) && grid[temp.x+1][temp.y] == 1) {
						if(!flag) {
							flag = true;
							ans++;
						}
						grid[temp.x+1][temp.y] = 2;

						temp.x++;
						Q.push(temp);
						temp.x--;
					}

					if (isValid(temp.x-1, temp.y, R, C) && grid[temp.x-1][temp.y] == 1) {
						if(!flag) {
							flag = true;
							ans++;
						}
						grid[temp.x-1][temp.y] = 2;

						temp.x--;
						Q.push(temp);
						temp.x++;
					}

					if (isValid(temp.x, temp.y+1, R, C) && grid[temp.x][temp.y+1] == 1) {
						if(!flag) {
							flag = true;
							ans++;
						}
						grid[temp.x][temp.y+1] = 2;

						temp.y++;
						Q.push(temp);
						temp.y--;
					}

					if (isValid(temp.x, temp.y-1, R, C) && grid[temp.x][temp.y-1] == 1) {
						if(!flag) {
							flag = true;
							ans++;
						}
						grid[temp.x][temp.y-1] = 2;

						temp.y--;
						Q.push(temp);
						temp.y++;
					}

					Q.pop();
				}
				Q.pop();

				if(!Q.empty()) {
					temp.x = -1;
					temp.y = -1;
					Q.push(temp);
				}
			}
			return checkAll(grid) ? ans : -1;
		}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}

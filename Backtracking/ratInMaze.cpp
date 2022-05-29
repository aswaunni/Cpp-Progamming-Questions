/*
Find the path for the mouse to escape the maze
*/

#include <bits/stdc++.h>

using namespace std;

bool isSafe(int** arr, int n, int i, int j) {
    return (i < n && j < n && arr[i][j]);
}

bool func(int** arr, int n, int i, int j, int** ans) {
    if (i == n-1 && j == n-1) {
        ans[i][j] = 1;
        return true;
    }

    if (isSafe(arr, n, i, j)) {
        ans[i][j] = 1;
        if (func(arr, n, i+1, j, ans) || func(arr, n, i, j+1, ans))
            return true;
            
        ans[i][j] = 0;
        return false;
    }
    return false;
}

int main()
{
    int**maze = new int*[5];
    for (int i = 0; i < 5; i++)
        maze[i] = new int[5];

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++)
            cin >> maze[i][j];
    }

    int** ans = new int*[5];
    for (int i = 0; i < 5; i++) {
        ans[i] = new int[5];
        for (int j = 0; j < 5; j++)
            ans[i][j] = 0;
    }
    cout << endl;
    func(maze, 5, 0, 0, ans);

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}

#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &A, int B) {
    int count = 0;
    int i = 0, n = A.size();

    if (B == 0)
        return -1;

    while (i < n) {
        int idx = -1;
        for (int j = max(0, i - B + 1); j < min(n, i + B); j++) {
            if (A[j] == 1)
                idx = j;
        }

        if (idx == -1) 
            return -1;

        count++;

        i = idx + B;
    }
    return count;
}



int main() {

	vector<int> A = {0, 0, 1, 1, 1, 0, 0, 1};
    int B = 3;
    
	cout << solve(A, B);
	
	return 0;
}

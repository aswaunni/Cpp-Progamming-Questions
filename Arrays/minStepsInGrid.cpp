#include <bits/stdc++.h>

using namespace std;

int coverPoints(std::vector<int>& A, std::vector<int>& B) {

    if (A.size() <= 1) 
        return 0;
    assert(A.size() == B.size());
    int steps = 0;
    for (int i = 1; i < A.size(); i++)
        steps += max(abs(A[i] - A[i-1]), abs(B[i] - B[i-1]));
    
    return steps;
}


int main() {

	vector<int> A = {0, 1, 1};
    vector<int> B = {0, 1, 2};
	cout << coverPoints(A, B);
}

/*
Building Towers Problem Code: TOWERTOP

Chef is given a contract to build towers in Chefland which are made by stacking blocks one above the other. Initially, there is only 1 block in the inventory and no tower has been built. Chef follows the following 2 steps in each operation:

Either build a new tower or update an existing tower that has been built in previous operations using any number of blocks currently present in the inventory. After this step, the size of the inventory reduces by the number of blocks used.
Suppose the tower Chef updated or built has B blocks after the step, Chef gets to add B new blocks to the inventory as a reward.
Find the maximum number of towers of height X that Chef can build in M operations.

Note: Tower of height X means that the tower consists of X blocks placed one above the other.

Input Format
First line will contain T, number of test cases. Then the test cases follow.
Each test case contains a single line of input, two space separated integers X,M.
Output Format
For each test case, output a single integer, the maximum number of towers that Chef can build.

Constraints
1≤T≤100
1≤X≤109
0≤M≤1017
Sample Input 1 
4
2 1
2 2
2 3
53 7
Sample Output 1 
0
1
2
1
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while (t--) {
	    long long x, m;
	    cin >> x >> m;
	    
	    long long minm = ceil(log2(x)) + 1;
	    cout << (m < minm ? 0 : m - minm + 1) << "\n";
	}
	return 0;
}

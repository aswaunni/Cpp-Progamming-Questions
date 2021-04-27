/*
Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle in a fixed direction.

The task is to choose the safe place in the circle so that when you perform these operations starting from 1st place in the circle, you are the last one remaining and survive.

Example 1:

Input:
n = 3 k = 2
Output: 3
Explanation: There are 3 persons so 
skipping 1 person i.e 1st person 2nd 
person will be killed. Thus the safe 
position is 3.

josephus(n, k) = (josephus(n - 1, k) + k-1) % n + 1

josephus(1, k) = 1
 */

#include <iostream>

using namespace std;
int josephus(int n, int k)
{
	return n > 1 ? (((josephus(n-1, k) + k - 1) % n)+1) : 1;

}

int main()
{
	cout<<josephus(5, 3);

	return 0;
}

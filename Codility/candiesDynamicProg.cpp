/*

Alice is a kindergarten teacher. She wants to give some candies to the children in her class.  All the children sit in a line and each of them has a rating score according to his or her performance in the class.  Alice wants to give at least 1 candy to each child. If two children sit next to each other, then the one with the higher rating must get more candies. Alice wants to minimize the total number of candies she must buy.

Example
arr = [4, 6, 4, 5, 6, 2]

She gives the students candy in the following minimal amounts: [1, 2, 1, 2, 3, 1]. She must buy a minimum of 10 candies.

Function Description

Complete the candies function in the editor below.

candies has the following parameter(s):

	int n: the number of children in the class
	int arr[n]: the ratings of each student
Returns

int: the minimum number of candies Alice must buy
Input Format

The first line contains an integer, n, the size of arr.
Each of the next n lines contains an integer arr[i] indicating the rating of the student at position i.

Sample Input 0

3
1
2
2
Sample Output 0

4

*/

long candies(int n, vector<int> arr) {
    vector<int> fromFront(n);
    vector<int> fromBack(n);
    
    fromFront[0] = 1;
    for (int i = 1; i < n; i++)
            fromFront[i] = ((arr[i] > arr[i-1]) ? fromFront[i-1] + 1 : 1);   

    fromBack[n-1] = 1;
    for (int i = n-2; i >= 0; i--)
            fromBack[i] = ((arr[i] > arr[i+1]) ? fromBack[i+1] + 1 : 1);
            
    long ans = 0;
    for (int i = 0; i < n; i++) {
        cout << fromFront[i] << " " << fromBack[i] << "\n";
        ans += max(fromFront[i], fromBack[i]);
    }    
    return ans;
}

/*
Given two lists V1 and V2 of sizes n and m respectively. Return the list of elements common to both the lists and return the list in sorted order. Duplicates may be there in the output list.

Example:

Input:
5
3 4 2 2 4
4
3 2 2 7

Output:
2 2 3

Explanation:
The first list is {3 4 2 2 4}, and the second list is {3 2 2 7}. 
The common elements in sorted order are {2 2 3}
*/

vector<int> common_element(vector<int>v1,vector<int>v2)
{
	vector<int> result(v1.size() + v2.size());

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());

	return result;
}

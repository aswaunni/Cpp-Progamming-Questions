/*
Given a list of non negative integers, arrange them in such a manner that they form the largest number possible.The result is going to be very large, hence return the result in the form of a string.

Example 1:

Input: 
N = 5
Arr[] = {3, 30, 34, 5, 9}
Output: 9534330
Explanation: Given numbers are {3, 30, 34,
5, 9}, the arrangement 9534330 gives the
largest value.
Example 2:

Input: 
N = 4
Arr[] = {54, 546, 548, 60}
Output: 6054854654
Explanation: Given numbers are {54, 546,
548, 60}, the arrangement 6054854654 
gives the largest value.
*/

string largestNumber(vector<int>& nums) {
    int n = nums.size();
    
    sort(nums.begin(), nums.end(), [] (int& a, int& b) {
        string c = to_string(a), d = to_string(b);
        return (c+d > d+c); 
    });
    
    string ans;
    for (auto& a : nums)
        ans += to_string(a);
    return (ans[0] == '0' ? "0" : ans);
}

//OR

string printLargest(vector<string> &arr) {
    string s;
    
    sort(arr.begin(), arr.end(), [] (string s1, string s2) 
    {
        return ((s1+s2) > (s2+s1));
    });
    
    for (int i = 0; i < arr.size(); i++)
        s += arr[i];
        
    return s;
}

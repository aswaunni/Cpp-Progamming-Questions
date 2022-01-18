/*
Given N activities with their start and finish day given in array start[ ] and end[ ]. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a given day.
Note : Duration of the activity includes both starting and ending day.


Example 1:

Input:
N = 2
start[] = {2, 1}
end[] = {2, 2}
Output: 
1
Explanation:
A person can perform only one of the
given activities.
Example 2:

Input:
N = 4
start[] = {1, 3, 2, 5}
end[] = {2, 4, 3, 6}
Output: 
3
Explanation:
A person can perform activities 1, 2
and 4.

//Hint 
Sort based on end times
*/

int activitySelection(vector<int> s, vector<int> e, int n)
{
    vector<pair<int,int>>v;
    
    for (int i = 0; i < n; i++)
        v.push_back({s[i],e[i]});
    
    sort(v.begin(), v.end(), [] (const pair<int,int> & a, const pair<int,int> & b) 
         { return a.second < b.second; });  
         
    int end = v.begin()->second;
    int ans = 1;
    
    for (auto& a : v) {
        if (a.first > end) {
            ans++;
            end = a.second;
        }
    }
    return ans;
}

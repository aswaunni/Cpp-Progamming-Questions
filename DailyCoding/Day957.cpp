/******************************************************************************

The skyline of a city is composed of several buildings of various widths and heights, possibly overlapping one another when viewed from a distance. We can represent the buildings using an array of (left, right, height) tuples, which tell us where on an imaginary x-axis a building begins and ends, and how tall it is. The skyline itself can be described by a list of (x, height) tuples, giving the locations at which the height visible to a distant observer changes, and each new height.

Given an array of buildings as described above, create a function that returns the skyline.

For example, suppose the input consists of the buildings [(0, 15, 3), (4, 11, 5), (19, 23, 4)]. In aggregate, these buildings would create a skyline that looks like the one below.

     ______  
    |      |        ___
 ___|      |___    |   | 
|   |   B  |   |   | C |
| A |      | A |   |   |
|   |      |   |   |   |
------------------------
As a result, your function should return [(0, 3), (4, 5), (11, 3), (15, 0), (19, 4), (23, 0)].

*******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>

using namespace std;

vector<pair<int, int>> helper(vector<tuple<int, int, int>>& v)
{
    vector<vector<int>> y;
    vector<pair<int, int>> ans;
    for (auto& a : v) {
        y.push_back({get<0>(a), get<2>(a)});
        y.push_back({get<1>(a), -get<2>(a)});
    }
    
    sort(y.begin(), y.end());
    
    multiset<int> s{0};
    int h = 0;
    
    for (auto& a : y) {
        if (a[1] < 0)
            s.erase(s.find(-a[1]));
        else
            s.insert(a[1]);
            
        int mx = *s.rbegin();
        if (mx != h) {
            h = mx;
            ans.push_back({a[0], h});
        }
    }
    return ans;
}


// main function
int main(){
    vector<tuple<int, int, int>> v = {
		{0, 15, 3},
		{4, 11, 5},
		{19, 23, 4},
	};
    
    auto ans = helper(v);
    for (auto& [a, b] : ans)
        cout << a << " " << b << endl;
	return 0;
}

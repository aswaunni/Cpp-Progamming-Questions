/*
The span of the stock prices today is defined as the maximum number of days(starting from today and going backwards) 
for which the price of the stock was less than or equal to today's price. find the span of the stock for all days.
*/


#include <bits/stdc++.h>

using namespace std;

vector<int> stockSpan(vector<int> v) {
    stack<pair<int, int>> s;
    vector<int> ans;
    
    for (auto& price : v) {
        int days = 1;
        while (!s.empty() && price >= s.top().first) {
            days += s.top().second;
            s.pop();
        }
        s.push({price, days});
        ans.push_back(days);
    }
    
    return ans;
}


int main() {
    
    vector<int> v{100, 80, 60, 70, 60, 75, 85};
    
    vector<int> ans = stockSpan(v);
    
    for (auto& a : ans)
        cout << a << ", ";
    cout << endl;
    
    return 0;
}

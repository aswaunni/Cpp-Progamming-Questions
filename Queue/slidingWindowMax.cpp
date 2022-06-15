#include <bits/stdc++.h>
using namespace std;

vector<int> slidingWindowMax(vector<int>& v, int n, int k) {
    deque<int> dq;
    vector<int> ans;

    for (int i = 0; i < k; i++) {
        while (!dq.empty() && dq.front() < v[i])
            dq.pop_front();
        dq.push_back(v[i]);
    }
    
    ans.emplace_back(dq.front());

    for (int i = k; i < n; i++) {
        if (dq.front() == v[i-k])
            dq.pop_front();

        while (!dq.empty() && dq.front() < v[i])
            dq.pop_front();
        dq.push_back(v[i]);
        
        ans.emplace_back(dq.front());
    }
    return ans;
}

int main() {
    vector<int> v = {1, 3, -1, -3, 5, 3, 6, 7};

    vector<int> ans = slidingWindowMax(v, 8, 3);
    for(auto& a: ans)
        cout << a << " ";
    cout << endl;
    return 0;
}

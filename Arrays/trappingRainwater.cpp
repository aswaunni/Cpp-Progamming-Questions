/*
Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
 

 Example 1:

 Input:
 N = 6
 arr[] = {3,0,0,2,0,4}
 Output:
 10
*/

int rainWaterTrapped(vector<int> v) {
    stack<int> s;
    int i = 0, ans = 0;
    
    while (i < v.size()) {
        if (s.empty() || v[i] < v[s.top()]) {
            s.push(i);
            i++;
        } else {
            int t = s.top();
            s.pop();
            if (!s.empty())
                ans += (min(v[i], v[s.top()]) - v[t]) * (i - s.top() - 1);
        }
    }
    return ans;
}

// OR

long long trappingWater(int arr[], int n){
    vector<int> rMax(n, 0);
    rMax[n-1] = arr[n-1];
    
    for (int i = n-2; i >= 0; i--)
        rMax[i] = max(rMax[i+1], arr[i]);
        
    int lMax = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        lMax = max(lMax, arr[i]);
        int x = min(lMax, rMax[i]);
        if (x > arr[i])
            ans += (x - arr[i]);
    }
    return ans;
}


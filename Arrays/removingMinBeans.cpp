/*
You are given an array of positive integers beans, where each integer represents the number of magic beans found in a particular magic bag.

Remove any number of beans (possibly none) from each bag such that the number of beans in each remaining non-empty bag (still containing at least one bean) is equal. Once a bean has been removed from a bag, you are not allowed to return it to any of the bags.

Return the minimum number of magic beans that you have to remove.

 

Example 1:

Input: beans = [4,1,6,5]
Output: 4
*/

long long minimumRemoval(vector<int>& beans) {
    int n = beans.size();
    long long sum = 0;
    for(int i = 0; i < n; ++i)
        sum += (long long)beans[i];
            
    sort(beans.begin(), beans.end());
    
    long long leftSum = 0;
    long long ans = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
        long long temp = sum - 1LL * (n - i) * beans[i];
        ans = min(temp, ans);
    }
    return ans;
}

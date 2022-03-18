/*
ou are given an integer finalSum. Split it into a sum of a maximum number of unique positive even integers.

For example, given finalSum = 12, the following splits are valid (unique positive even integers summing up to finalSum): (12), (2 + 10), (2 + 4 + 6), and (4 + 8). Among them, (2 + 4 + 6) contains the maximum number of integers. Note that finalSum cannot be split into (2 + 2 + 4 + 4) as all the numbers should be unique.
Return a list of integers that represent a valid split containing a maximum number of integers. If no valid split exists for finalSum, return an empty list. You may return the integers in any order.
*/

vector<long long> maximumEvenSplit(long long finalSum) {
    if (finalSum%2 == 1)
        return {};
    
    vector<long long> ans;
    
    int x = 2;
    while (finalSum >= x) {
        ans.push_back(x);
        finalSum -= x;
        x += 2;
    }
    ans[ans.size() - 1] += finalSum;
    return ans;
}

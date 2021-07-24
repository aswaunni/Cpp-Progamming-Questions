/*
You are planning production for an order. You have a number of machines that each have a fixed number of days to produce an item. Given that all the machines operate simultaneously, determine the minimum number of days to produce the required order.

For example, you have to produce goal = 10 items. You have three machines that take machines = [2, 3, 2] days to produce an item. The following is a schedule of items produced:

Day Production  Count
2   2               2
3   1               3
4   2               5
6   3               8
8   2              10
It takes 8 days to produce 10 items using these machines.

Function Description

Complete the minimumTime function in the editor below. It should return an integer representing the minimum number of days required to complete the order.

minimumTime has the following parameter(s):

machines: an array of integers representing days to produce one item per machine
goal: an integer, the number of items required to complete the order
Input Format

The first line consist of two integers n and goal, the size of machines and the target production.
The next line contains n space-separated integers, machines[i].

Constraints
	1 <= n <= 10e5
	1 <= goal <= 10e9
	1 <= machines[i] <= 10e9
Output Format

Return the minimum time required to produce goal items considering all machines work simultaneously.

Sample Input 0

2 5
2 3
Sample Output 0

6
*/

//Brute Force

long minTime(vector<long> machines, long goal) {
    long days = 0, itemCnt = 0;
    while (itemCnt < goal) {
        days++;
        for (long i = 0; i < machines.size(); i++) {
            if (days%machines[i] == 0)
                itemCnt++;
        }
    }
    return days;
}

//Efficient

long minTime(vector<long> machines, long goal) {
    long low = 1, high = 1e18;
    long ret = 0;
    while (low <= high) {
        long mid = (low + high)/2;
        long cnt = 0;
        for (long i = 0; i < machines.size(); i++) {
            cnt += mid/machines[i];
            if (cnt >= goal)
                break;
        }
        
        if (cnt >= goal) {
            high = mid - 1;
            ret = mid;
        } else {
            low = mid + 1;
        }
    }
    return ret;
}

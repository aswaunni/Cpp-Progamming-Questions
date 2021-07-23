/*

HackerLand National Bank has a simple policy for warning clients about possible fraudulent account activity. If the amount spent by a client on a particular day is greater than or equal to  2*he client's median spending for a trailing number of days, they send the client a notification about potential fraud. The bank doesn't send the client any notifications until they have at least that trailing number of prior days' transaction data.

Given the number of trailing days d and a client's total daily expenditures for a period of n days, determine the number of times the client will receive a notification over all n  days.Function Description

Complete the function activityNotifications in the editor below.

activityNotifications has the following parameter(s):

int expenditure[n]: daily expenditures
int d: the lookback days for median spending
Returns

int: the number of notices sent
Input Format

The first line contains two space-separated integers n and d  the number of days of transaction data, and the number of trailing days' data used to calculate median spending respectively.
The second line contains n space-separated non-negative integers where each integer i denotes expenditure[i].

*/

int activityNotifications(vector<int> expenditure, int d) {
    vector<int> cnt(201, 0);
    int n = expenditure.size();
    int res = 0;
    
    for (int i = 0; i < d; i++)
        cnt[expenditure[i]]++;
        
    for (int i = d; i < n; i++) {
        int acc = 0;
        int min_median = -1, max_median = -1;
        
        for (int j = 0; j <= 200; j++) {
            acc += cnt[j];
            
            if (min_median == -1 && acc >= (int)floor((d+1)/2.0))
                min_median = j;
                
            if (max_median == -1 && acc >= (int)ceil((d+1)/2.0))
                max_median = j;
        }
        
        if (expenditure[i] >= (min_median + max_median))
            res++;
            
        cnt[expenditure[i-d]]--;
        cnt[expenditure[i]]++;
    }
    return res;
}

/*
You are given an array a1,a2,…,an, consisting of n integers. You are also given an integer value x.

Let f(k) be the maximum sum of a contiguous subarray of a after applying the following operation: add x to the elements on exactly k distinct positions. An empty subarray should also be considered, it has sum 0.

Note that the subarray doesn't have to include all of the increased elements.

Calculate the maximum value of f(k) for all k from 0 to n independently.

Input
The first line contains a single integer t (1≤t≤5000) — the number of testcases.

The first line of the testcase contains two integers n and x (1≤n≤5000; 0≤x≤105) — the number of elements in the array and the value to add.

The second line contains n integers a1,a2,…,an (−105≤ai≤105).

The sum of n over all testcases doesn't exceed 5000.

Output
For each testcase, print n+1 integers — the maximum value of f(k) for all k from 0 to n independently.

Example
inputCopy
3
4 2
4 1 3 2
3 5
-2 -7 -1
10 2
-6 -1 -2 4 -6 -1 -4 4 -5 -4
outputCopy
10 12 14 16 18
0 4 4 5
4 6 6 7 7 7 7 8 8 8 8
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	scanf("%d", &t);
	while (t--) {
		scanf("%d%lld", &n, &x);
		for (int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
 
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++)
				dp[i][j] = 0;
			ans[i] = 0;
		}
 
		for (int i = 1; i <= n; i++) {
 
			for (int j = 0; j <= n; j++) {
				dp[i][j] = max(0ll, dp[i - 1][j] + a[i]);
				if (j) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i] + x);
				ans[j] = max(ans[j], dp[i][j]);
			}
 
		}
		for (int i = 0; i <= n; i++)
			printf("%lld ", ans[i]);
		printf("\n");
 
	}
	
}

// OR

void solve()
{
    ll n, x; cin>>n>>x;
    vector<ll> a(n); for (int i = 0; i<n; i++) cin>>a[i];
 
    vector<ll> sums(n+1, -1e18);
 
    sums[0] = 0;
    for (int i = 0; i<n; i++)
    {
        ll cur = 0;
        for (int j = i; j<n; j++)
        {
            cur+=a[j];
            sums[j-i+1] = max(sums[j-i+1], cur);
        }
    }
 
    vector<ll> ans(n+1, -1e18);
    for (int take = 0; take<=n; take++)
    {
        for (int i = 0; i<=n; i++)
        {
            ll res = sums[i] + x*min(take, i);
            ans[take] = max(ans[take], res);
        }
    }
 
    for (auto it: ans) cout<<it<<' ';
    cout<<endl;
 
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int t; cin>>t;
    while (t--) solve();
 
}


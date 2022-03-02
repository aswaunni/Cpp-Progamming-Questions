/*
You are given an array A of N integers . You want to convert the array A into a permutation of N integers. To do this, you can apply the following operation on array A exactly once .

Pick an integer X, where 1≤X≤2⋅107. For each i , 1≤i≤N , replace Ai by Ai%X.
Find out whether it is possible to convert A into a permutation of N integers. If it is possible, print YES (all uppercase alphabets) and any possible value of X for which it is possible. Otherwise, print NO (all uppercase alphabets).

Note - An array of N integers is called a permutation if it contains all integers from 1 to N exactly once.

Input Format
The first line contains an integer T denoting the number of test cases. The T test cases then follow.
The first line of each test case contains an integer N.
The second line of each test case contains N space-separated integers A1,A2,…,AN.
Output Format
For each testcase, output the required answer in a single line. If an answer exists, print YES and an integer X (1≤X≤2⋅107) separated by a single space. Otherwise, print NO.

Note that the strings are case-sensitive and must be in uppercase alphabets.

Constraints
1≤T≤100
1≤N≤105
1≤Ai≤107
Sum of N over all cases won't exceed 105
Subtasks
Subtask #1 (100 points): original constraints

Sample Input 1 
2
3
2 7 1
2
2 2
Sample Output 1 
YES 4
NO
*/

// editorial : https://discuss.codechef.com/t/magicmod-editorial/99584

#include<bits/stdc++.h>
using namespace std;

#define int long long

bool check(vector<int> a, int n, int x, int s){
	if(s%x != 0) 
	    return false;
	    
	vector<bool> vis(n+1, false);
	for(int i=1; i<=n ;i++){
		if(a[i]%x==0 || a[i]%x>n || vis[a[i]%x]) 
		    return false;
		vis[a[i]%x]=true;
	}
	return true;
}

void solve()
{
  int n;
  cin>>n;
  int s = 0;

  vector<int> a(n+1);
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];
    s += a[i];
  }

  s -= (n*(n+1))/2;

  if (s == 0)
    cout <<"YES " << n+1 << "\n";
  else if (s < 0)
    cout << "NO" << "\n";
  else {
    for (int i = 1; i * i <= s ; i++) {
      if (s % i == 0) {
        if(check(a, n, i, s) && i <= 2e7) {
            cout << "YES " << i << '\n';
            return;
        }
        if(check(a, n, s/i, s) && (s/i) <= 2e7) {
            cout << "YES " << s/i << '\n';
            return;
        }
      }
    }
    cout << "NO\n";
  }
}

int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin>>t;

  while(t--)
    solve();

return 0;
}

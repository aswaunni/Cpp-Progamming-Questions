/*
You are given an integer N. Find the number of distinct XORs it is possible to make using two positive integers no larger than N.

Formally, let S be the set
S={x⊕y∣1≤x,y≤N}
where ⊕ denotes the bitwise XOR operation.

Find |S| (where |S| denotes the size of set S. Note that a set, by definition, has no repeated elements). The answer might be large, so output it modulo 109+7.

Input Format
The first line of input contains a single integer T, denoting the number of test cases. The description of T test cases follows.
Each test case consists of a single line of input, which contains one integer N.
Output Format
For each test case, output a single line containing the answer, modulo 109+7.

Constraints
1≤T≤105
1≤N≤1012
Sample Input 1 
3
1
3
7
Sample Output 1 
1
4
8
Explanation
Test Case 1: N=1, so the only XOR we can possibly make is 1⊕1=0. Thus, the answer is 1.

Test Case 2: N=3, which gives us S={0,1,2,3} as the set of possible XORs. Thus, the answer is |S|=4.
*/

//1

int main() {

    fio;

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll p = 1;
        while (p < n)
        {
            p *= 2;
        }
        if (p == n)
        {
            p *= 2;
            p--;
        }
        if(n==2)
            cout<<2<<endl;
        else
        cout << (p % mod + mod) % mod << endl;
    }

    return 0;
}

//2

#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
typedef long long int ll;
ll power(ll x, ll y)
{
    ll result = 1;
    while (y > 0) {
        if (y % 2 == 0) // y is even
        {
            x = (x%mod * x%mod)%mod;
            y = y / 2;
        }
        else // y isn't even
        {
            result = (result%mod * x%mod)%mod;
            y = y - 1;
        }
    }
    result=result%mod;
    return result;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll cnt=0;
        ll val=n;
        if(n==2)
        {
            cout<<"2"<<endl;
            continue;
        }
        while(val!=1)
        {
            val=val/2;
            cnt++;
        }
        ll val2=power(2,cnt);
        ll val3=power(2,cnt+1);
        if(val2==n)
        {
            cout<<(val3-1)%mod<<"\n";
        }
        else
        {
            cout<<val3%mod<<"\n";

        }
    }
    return 0;
}

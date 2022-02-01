/*
Monocarp is playing a computer game. In this game, his character fights different monsters.

A fight between a character and a monster goes as follows. Suppose the character initially has health hC and attack dC; the monster initially has health hM and attack dM. The fight consists of several steps:

the character attacks the monster, decreasing the monster's health by dC;
the monster attacks the character, decreasing the character's health by dM;
the character attacks the monster, decreasing the monster's health by dC;
the monster attacks the character, decreasing the character's health by dM;
and so on, until the end of the fight.
The fight ends when someone's health becomes non-positive (i. e. 0 or less). If the monster's health becomes non-positive, the character wins, otherwise the monster wins.

Monocarp's character currently has health equal to hC and attack equal to dC. He wants to slay a monster with health equal to hM and attack equal to dM. Before the fight, Monocarp can spend up to k coins to upgrade his character's weapon and/or armor; each upgrade costs exactly one coin, each weapon upgrade increases the character's attack by w, and each armor upgrade increases the character's health by a.

Can Monocarp's character slay the monster if Monocarp spends coins on upgrades optimally?

Input
The first line contains one integer t (1≤t≤5⋅104) — the number of test cases. Each test case consists of three lines:

The first line contains two integers hC and dC (1≤hC≤1015; 1≤dC≤109) — the character's health and attack;

The second line contains two integers hM and dM (1≤hM≤1015; 1≤dM≤109) — the monster's health and attack;

The third line contains three integers k, w and a (0≤k≤2⋅105; 0≤w≤104; 0≤a≤1010) — the maximum number of coins that Monocarp can spend, the amount added to the character's attack with each weapon upgrade, and the amount added to the character's health with each armor upgrade, respectively.

The sum of k over all test cases does not exceed 2⋅105.

Output
For each test case, print YES if it is possible to slay the monster by optimally choosing the upgrades. Otherwise, print NO.

Example
inputCopy
4
25 4
9 20
1 1 10
25 4
12 20
1 1 10
100 1
45 2
0 4 10
9 2
69 2
4 2 7
outputCopy
YES
NO
YES
YES
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
	int t;
	cin >> t;
	
	while (t--) {
        ll hc, dc, hm, dm;
		cin >> hc >> dc >> hm >> dm;
    
		ll k, w, a;
		cin >> k >> w >> a;
		
		bool flag = false;
    
		for (int i = 0; i <= k; i++) {
			ll h = hc + a * i;
			ll d = dc + w * (k - i);
        
			ll cm = (hm + d - 1) / d;
			ll mc = (h + dm - 1) / dm;
        
			if (cm <= mc) {
				flag = true;
				break;
			}
		}		
		cout << (flag ? "YES" : "NO") << "\n";
	}
	return 0;
}

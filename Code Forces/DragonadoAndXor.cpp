/*
Dragonado rarely gets stuck on a problem, unless of course, if it's a XOR Problem.

Dragonado while coming back from the Fruit Market, finds an array A of N elements. He wants to find 4 integers, say i1,i2,i3 and i4, such that:

popcount(Ai1⊕Ai2)=popcount(Ai3⊕Ai4)
1≤i1,i2,i3,i4≤N and i1,i2,i3,i4 are pairwise distinct.
Here, popcount(x) denotes the number of set bits in the binary representation of x. Secondly, ⊕ denotes the bitwise XOR operation.

Can you help Dragonado find four integers i1,i2,i3 and i4 which satisfy the given conditions?

Output −1 if no answer exists.

If multiple answers exist, output any.

Note: The input of this problem is large, so use fast input/output methods.

Input Format
The first line contains a single integer T - the number of test cases. Then the test cases follow.
The first line of each test case contains an integer N - the size of the array A.
The second line of each test case contains N space-separated integers A1,A2,…,AN denoting the array A.
Output Format
For each test case, output i1,i2,i3,i4 which satisfy the given conditions.

Output −1 if no numbers satisfying the conditions exist.

Constraints
1≤T≤104
4≤N≤105
1≤Ai≤109
It is guaranteed that sum of N over all test cases does not exceed 2⋅106
Sample Input 1 
2
4
1 2 5 6
4
1 2 3 4
Sample Output 1 
1 4 2 3
-1

//COncept : Pigeon hole - In mathematics, the pigeonhole principle states that if {\displaystyle n}n items are put into {\displaystyle m}m containers, with {\displaystyle n>m}n>m, then at least one container must contain more than one item.[1] For example, if one has three gloves (and none is ambidextrous/reversible), then there must be at least two right-handed gloves, or at least two left-handed gloves, because there are three objects, but only two categories of handedness to put them into. 
// max is 10^9 which can be represented with 30 bits, so if we select 31 pairs atleast one would have 2.

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

#define INF INT_MAX
#define MOD 1000000007
#define all(x) x.begin(), x.end()

int pc(int x){
    return __builtin_popcount(x);
}

void brute(int N, vi A){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j) continue;

            for(int k = 0; k < N; k++){
                if(i == k or j == k) continue;

                for(int l = 0; l < N; l++){
                    if(i == l or j == l or k == l) continue;

                    if(pc(A[i]^A[j]) == pc(A[k]^A[l])){
                        cout << i+1 << " " << j+1 << " "
                                << k+1 << " " << l+1 << endl;
                        return;
                    }
                }
            }
        }
    }

    cout << -1 << endl;
    return;
}

void solve(int N, vi A){
    vi found(32, -1);
    for(int x = 0; x < N-1; x += 2){
        int z = pc(A[x]^A[x+1]);
        if(found[z] != -1){
            cout << found[z]+1 << " " << found[z]+2 << " "
                    << x+1 << " " << x+2 << endl;
            return;
        }
        found[z] = x;
    }

    // Should never happen!
    assert(false);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        vi A(N); for(auto &i : A) cin >> i;

        if(N <= 69) brute(N, A);
        else solve(N, A);
    }

    return 0;
}

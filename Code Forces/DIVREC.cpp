/*
Alice is teaching Bob maths via a game called N-guesser.

Alice has a positive integer N which Bob needs to guess. She gives him two pieces of information with which to do this:

A positive integer X, which denotes the sum of divisors of N.
Two positive integers A and B, which denote that the sum of reciprocals of divisors of N is A/B.
Bob either needs to guess N or tell that no such number exists.

It can be shown that if a valid N exists, it is unique.

Input Format
The first line of input contains a single integer T, denoting the number of test cases. The description of T test cases follows.
Each test case consists of a single line of input, containing three space-separated integers X,A,B.
Output Format
For each test case, output a new line containing the answer — Alice's number N, or −1 if no such number exists.

Constraints
1≤T≤1000
1≤X≤109
1≤A,B≤109
gcd(A,B)=1
Sample Input 1 
2
4 4 3
4 1 1
Sample Output 1 
3
-1

//HINT
The divisors of a number n are of the form a_1, n/a_1, a_2, n/a_2...sqrt(n) (only if it divides n). So, the sum of reciprocal of the divisors of a number is nothing but the sum of divisors of the number divided by the number n itself.
So, we can the get the number n as X*B/A. But, we have to check that this n yields the same sum of the divisors as given input X, which will require O(sqrt(n)) time.
*/

int main() {
	int t;
	cin >> t;
	while(t--) {
	    long long x, a, b;
	    cin >> x >> a >> b;
	    long long n = x * b;
	    if (n % a != 0 || b > a) {
	        cout << "-1\n";
	        continue;
	    }
	    
	    n /= a;
        
	    long long sum = 0;
	    for (int i = 1; i <= sqrt(n); i++) {
	        if (n%i == 0) {
	            sum += i;
	            if (i != n/i)
	                sum += n/i;
	        }      
	    }
	    
	    cout << (x == sum ? n : -1) << "\n";
	}
	return 0;
}

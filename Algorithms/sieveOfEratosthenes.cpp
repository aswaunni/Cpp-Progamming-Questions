/*
---------------------
Sieve of Eratosthenes
---------------------

The sieve of Eratosthenes is one of the most efficient ways to find all primes smaller than n when n is smaller than 10 million
It follows where each non-prime element’s index is marked as 1 inside the nested loops. The prime numbers are those whose index is marked as 0.
*/

void primeSieve(int n) 
{
    bool arr[n] = {false};
    
    for (int i = 2; i <= sqrt(n); i++) {
        if (!arr[i]) {
            for (int j = i*i; j <= n; j+=i)
                arr[j] = true;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (!arr[i])
            cout << i << ", ";
    }

}

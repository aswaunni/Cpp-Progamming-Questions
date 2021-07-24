bool isPrime(int n) {
    if (n == 2)
        return true;
    if (n == 1 || n%2 == 0)
        return false;
        
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n%i == 0)
            return false;
    }
    return true;
}

string primality(int n) {
    return (isPrime(n) ? "Prime" : "Not prime");
}

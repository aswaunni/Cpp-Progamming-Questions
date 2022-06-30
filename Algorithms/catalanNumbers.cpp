/*
Catalan numbers
c0 = 1, c1 = 1
cn = sum(ci * c(n-i))
Eg. c2 = c0*c1 + c1*c0;
    c3 = c0*c2 + c1*c1 + c2*c0;
    
Applications of Catalan numbers
-------------------------------
1. Possible BSTs with n nodes
2. Parenthesis/Bracket combinations
3. Possible forests
4. Ways of triangulation
5. Possible paths in Matrix
6. Divinding a circle using n chords
7. Dyck words of given length
*/

int catalan(int n) {
    if (n == 0 || n == 1)
        return 1;
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += catalan(i) * catalan(n-i-1);
    return ans;
}

int main()
{
    cout << catalan(4);
    
    return 0;
}

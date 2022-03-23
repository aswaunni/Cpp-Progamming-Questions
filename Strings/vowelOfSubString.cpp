/*

Given a string word, return the sum of the number of vowels ('a', 'e', 'i', 'o', and 'u') in every substring of word.

A substring is a contiguous (non-empty) sequence of characters within a string.

Note: Due to the large constraints, the answer may not fit in a signed 32-bit integer. Please be careful during the calculations.

*******A char at position i appears in (i + 1) * (sz - i) substrings.***********

*/

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

long long countVowels(string s) {
    long res = 0, n = s.size();
    for (int i = 0; i < n; ++i)
        if (isVowel(s[i]))
            res += (i + 1) * (n - i);
    return res;
}

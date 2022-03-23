/*
You are given an integer n indicating there are n specialty retail stores. There are m product types of varying amounts, which are given as a 0-indexed integer array quantities, where quantities[i] represents the number of products of the ith product type.

You need to distribute all products to the retail stores following these rules:

A store can only be given at most one product type but can be given any amount of it.
After distribution, each store will have been given some number of products (possibly 0). Let x represent the maximum number of products given to any store. You want x to be as small as possible, i.e., you want to minimize the maximum number of products that are given to any store.
Return the minimum possible x.

 

Example 1:
Input: n = 6, quantities = [11,6]
Output: 3

Example 2:
Input: n = 7, quantities = [15,10,10]
Output: 5

Example 3:
Input: n = 1, quantities = [100000]
Output: 100000

*******BINARY SEARCH*************
*/

int minimizedMaximum(int n, vector<int>& q) {
    int l = 1, r = 100000;
    
    while (l < r) {
        int m = (l + r) / 2; // m is the number items per store
        long long sum = 0;
        for (auto& a : q)
            sum += (a + m - 1)/m; // equivalent to ceil(a/m)
        if (sum > n) // number of stores are lesser
            l = m + 1;
        else
            r = m;
    }
    return l;
}

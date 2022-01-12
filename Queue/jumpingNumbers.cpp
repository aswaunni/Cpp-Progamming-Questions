/*
Given a positive number X. Find the largest Jumping Number smaller than or equal to X. 
Jumping Number: A number is called Jumping Number if all adjacent digits in it differ by only 1. All single digit numbers are considered as Jumping Numbers. For example 7, 8987 and 4343456 are Jumping numbers but 796 and 89098 are not.

 

Example 1:

Input:
X = 10
Output:
10
Explanation:
10 is the largest Jumping Number
possible for X = 10.
Example 2:

Input:
X = 50
Output:
45
Explanation:
45 is the largest Jumping Number
possible for X = 50.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function jumpingNums() which takes an Integer X as input and returns the largest Jumping Number less than or equal to X.

 

Expected Time Complexity: O(k), where k is no of jumping numbers
Expected Auxiliary Space: O(k), where k is no of jumping numbers

 

Constraints:
1 <= X <= 109

//HINT

Imagine a graph
1 -> 10 11
2 -> 21 23
...
*/

long long jumpingNums(long long X) {
    queue<long long> q;
    long long ans = 0;
    for (int i = 1; i <= 9; i++) {
        q.push(i);
        
        while(!q.empty()) {
            long long num = q.front();
            q.pop();
            
            if (num <= X) {
                ans = max(num, ans);
                
                int lastDigit = num%10;
                if (lastDigit == 0)
                    q.push(num*10 + lastDigit + 1);
                else if (lastDigit == 9)
                    q.push(num*10 + lastDigit - 1);
                else {
                    q.push(num*10 + lastDigit + 1);
                    q.push(num*10 + lastDigit - 1);
                }
            }
        }
    }
    return ans;
}

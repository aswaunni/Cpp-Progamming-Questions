/*
-----------------------------------------
TOWER OF HANOI
-----------------------------------------

Tower of Hanoi is a mathematical puzzle where we have three rods and n disks. The objective of the puzzle is to move the entire stack to another rod,
obeying the following simple rules: 

* Only one disk can be moved at a time.
* Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the u
ppermost disk on a stack.
* No disk may be placed on top of a smaller disk.
*/

#include <bits/stdc++.h>

using namespace std;

void tower(int n, char s, char d,char h)
{
    if (n == 0)
        return;
    tower(n-1, s, h, d);
    cout << "Moving from " << s << " to " << d << endl;
    tower(n-1, h, d, s);
}

int main()
{

    int n;
    cout << "Enter n: ";
    cin >> n;
    tower(n, 's', 'd', 'h');
    return 0;
}

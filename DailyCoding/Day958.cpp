/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<string> helper(vector<pair<string, string>>& flights, string start)
{
    vector<string> ans = {start};
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> pq;
    for (auto & a : flights)
        pq[a.first].push(a.second);
        
    while (true) {
        if (!pq.contains(start) || pq[start].empty())
            break;
            
        auto nextDest = pq[start].top();
        pq[start].pop();
        ans.push_back(nextDest);
        start = nextDest;
    }
    return (ans.size() == flights.size()+1) ? ans : vector<string>();
}

// main function
int main(){
    vector<pair<string, string>> flights = {
        {"A", "B"},
        {"A", "C"},
        {"B", "C"},
        {"C", "A"},
        {"C", "D"}
    };
    
    auto ans = helper(flights, "A");
	for (auto& a : ans)
	    cout << a << " ";
	cout << endl;
	
	flights = {
        {"SFO", "HKO"},
        {"YYZ", "SFO"},
        {"YUL", "YYZ"},
        {"HKO", "ORD"}
    };
    
    ans = helper(flights, "YUL");
	for (auto& a : ans)
	    cout << a << " ";
	cout << endl;
	return 0;
}

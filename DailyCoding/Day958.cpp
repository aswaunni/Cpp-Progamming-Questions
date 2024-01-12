/******************************************************************************
[MEDIUM]

This problem was asked by Facebook.

Given an unordered list of flights taken by someone, each represented as (origin, destination) pairs, and a starting airport, compute the person's itinerary. If no such itinerary exists, return null. If there are multiple possible itineraries, return the lexicographically smallest one. All flights must be used in the itinerary.

For example, given the list of flights [('SFO', 'HKO'), ('YYZ', 'SFO'), ('YUL', 'YYZ'), ('HKO', 'ORD')] and starting airport 'YUL', you should return the list ['YUL', 'YYZ', 'SFO', 'HKO', 'ORD'].

Given the list of flights [('SFO', 'COM'), ('COM', 'YYZ')] and starting airport 'COM', you should return null.

Given the list of flights [('A', 'B'), ('A', 'C'), ('B', 'C'), ('C', 'A')] and starting airport 'A', you should return the list ['A', 'B', 'C', 'A', 'C'] even though ['A', 'C', 'A', 'B', 'C'] is also a valid itinerary. However, the first one is lexicographically smaller.

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

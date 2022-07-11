/*
You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.

For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between bus stops by buses only.

Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.

Example 1:
Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
Output: 2
Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
Example 2:
Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
Output: -1
*/

 int numBusesToDestination(vector<vector<int>>& routes, int s, int e) {
     unordered_map<int, vector<int>> fromStop; // buses that can be boarded from each stop
     
     for(int i = 0; i < routes.size(); i++) {
         for (int j : routes[i])
             fromStop[j].push_back(i);
     }
     
     unordered_map<int, bool> vis_stops;
     queue<pair<int, int>> q;
     q.push({s, 0});
     vis_stops[s] = true;
     
     while (!q.empty()) {
         int stop = q.front().first, bus = q.front().second;
         q.pop();
         
         if (stop == e)
             return bus;
         for (int i : fromStop[stop]) {
             for (int j : routes[i]) {
                 if (!vis_stops[j]) {
                     q.push({j, bus+1});
                     vis_stops[j] = true;
                 }
             }
             routes[i].clear();
         }
     }
     return -1;
 }

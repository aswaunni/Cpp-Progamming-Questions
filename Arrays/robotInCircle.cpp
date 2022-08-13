/*
On an infinite plane, a robot initially stands at (0, 0) and faces north. Note that:

The north direction is the positive direction of the y-axis.
The south direction is the negative direction of the y-axis.
The east direction is the positive direction of the x-axis.
The west direction is the negative direction of the x-axis.
The robot can receive one of three instructions:

"G": go straight 1 unit.
"L": turn 90 degrees to the left (i.e., anti-clockwise direction).
"R": turn 90 degrees to the right (i.e., clockwise direction).
The robot performs the instructions given in order, and repeats them forever.

Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

 

Example 1:

Input: instructions = "GGLLGG"
Output: true
Example 2:

Input: instructions = "GG"
Output: false

Example 3:

Input: instructions = "GL"
Output: true

*/

bool isRobotBounded(string instructions) {
    vector<vector<int>> dir = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    
    int d = 0;
    int i = 0, j = 0;
    
    for (auto& c : instructions) {
        if (c == 'L')
            d = (d+1)%4;
        else if (c == 'R')
            d = (d+3)%4;
        else {
            i += dir[d][0], j += dir[d][1];
        }
    }
    return ((i == 0 && j == 0) || d > 0);
}

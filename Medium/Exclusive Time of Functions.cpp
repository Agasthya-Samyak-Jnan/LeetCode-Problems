#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/exclusive-time-of-functions/
// Difficulty : Medium

// STACK-BASED PROBLEM THAT CAN ALSO BE SOLVED USING RECURSION
/* 
    - This is a fundamentally stack-based problem because a single-threaded CPU can execute ONE task at a time.
    - The current task has to be ended before any other action can be done like starting/stopping of other tasks.
    - This results in a randomly nested intervals pattern if you visualize it on a paper, where no intervals overlap on each other.
    - You can then find execution time of every function by subtracting the execution times of intervals inside its execution time interval from its total execution time.
    - Then add and store the execution times in another array for every interval for each function.
*/

class Solution {
public:

    // To parse function id, timestamp and start/stop action.
    vector<int> parse_log (string log) {

        int i = 0, func, action, timestamp;

        string temp = "";
        while (log[i] != ':') { temp += log[i]; i++; }
        func = stoi(temp);

        i++;
        if (log[i] == 's') { action = 1; i += 6; }
        else { action = 0; i+= 4; }

        temp = "";
        while (log[i]) { temp += log[i]; i++; }
        timestamp = stoi(temp);

        return {func,action,timestamp};
    }

    vector<int> exclusiveTime(int n, vector<string>& logs) {

        vector<int> times(n,0);
        stack<vector<int>> s;

        for (auto log : logs) {

            vector<int> temp = parse_log(log);
            int func = temp[0];
            int action = temp[1]; // '1' -> start | '0' -> stop
            int timestamp = temp[2];

            if (action == 1) { s.push({func,timestamp,0}); } 
            else {
                int f_interval = timestamp - s.top()[1] + 1;
                int time_to_add = f_interval - s.top()[2];
                s.pop();
                times[func] += time_to_add;
                if (!s.empty()) { s.top()[2] += f_interval; }
            }

        }
        
        return times;
    }
};
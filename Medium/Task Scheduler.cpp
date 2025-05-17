#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/task-scheduler/
// Difficulty : Medium 

/* INTUITION + GREEDY : 
    - "MOST" FREQUENT TASK CAUSES MOST WAITING TIME, THINK WHY FOR A MINUTE.
    - "MOST" FREQUENT TASK WILL CREATE MOST INTERVALS WHERE YOU CAN FIT YOUR OTHER TASKS INSIDE BEFORE REPEATING SAME TASK AGAIN.
    - NUMBER OF INTERVALS CREATED = (FREQUENCY OF MOST REPEATED TASK - 1)
    - TASKS YOU CAN FIT BETWEEN SUCH INTERVALS WOULD BE = (INTERVALS CREATED)*(n+1) , Where '+1' refers to "MOST" Repeating Task itself.
    - IF THERE ARE MORE "MOST" FREQUENT TASKS THAN ALLOWED INTERVAL BETWEEN REPEATED TASKS, 
      THEN YOU CAN DO ONE AFTER ANOTHER WITHOUT WAITING SINCE THERE ARE MORE TASKS CREATE A GAP LARGER THAN REQUIRED INTERVAL BETWEEN REPEATED TASKS.
      HENCE, YOU DON'T NEED IDLE TIME AND ALL INTERVALS ARE UTILISED BY TASKS, HENCE TAKES "NUMBER OF TASKS" INTERVALS TO COMPLETE.
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        int freq[26] = {0}, max_rep_cnt = 0, intervals = 0, cnt_of_max_rep_task = 0, taskcount = tasks.size();

        for (auto task : tasks) { 
            freq[task-'A']++;
            max_rep_cnt = max(max_rep_cnt,freq[task-'A']);
        }

        for (auto f : freq) { cnt_of_max_rep_task += (f == max_rep_cnt); }

        if (cnt_of_max_rep_task <= n) { intervals = max((max_rep_cnt-1)*(n+1)+cnt_of_max_rep_task,taskcount); }
        else { intervals = taskcount; }
        
        return intervals;
    }
};

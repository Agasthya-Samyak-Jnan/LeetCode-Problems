#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/jump-game-ii/
// Difficulty : Medium

/* GREEDY FOR JUMPING FARTHEST */
/* Approach By Own Intuition */
class Solution {
public:
    int jump (vector<int>& nums) {
        int curr_pos=nums.size()-1,jumps=0;

        while (curr_pos != 0) {
            int x = curr_pos;
            for (int i=curr_pos;i>=0;i--) {
                if (i+nums[i] >= curr_pos) { x = i; }
            }
            curr_pos = x;
            jumps++;
        }
    
        return jumps;
    }

};

/* Intuition got Optimized - Concept of Maximum Sized Reachable Spaces formed during Jumps. */
int jump(vector<int>& nums) {

        int n = nums.size(),jumps=0,curr_end=0;

        for (int max_reach = 0,i=0;i<n-1 && i<=max_reach;i++) {
            max_reach = max(max_reach,i+nums[i]);

            if (i == curr_end) {
                curr_end = max_reach; jumps++;
            }
        }
        
        return jumps;    
    }

/* TESTER CODE */
int main () {

    Solution* a = new Solution();
    vector<vector<int>> nums ={{2,3,1,1,4},{2,5,0,0},{3,0,8,2,0,0,1},{2,0},{0}};
    for (auto i : nums) { cout<<a->jump(i)<<" "; }

    return 0;
}
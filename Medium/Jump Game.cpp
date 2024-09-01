#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/jump-game/
// Difficulty : Medium

/* GREEDY FOR JUMPING FARTHEST */
/* Approach By Own Intuition */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size(),i=0;

        if (n == 1) { return true; }
        
        while (i < n && i != n-1) {
            int k = i;
            for (int j=i+1;j<n && j<=i+nums[i];j++) {
                if (j + nums[j] >= n-1) { return true; }
                if (j + nums[j] > k + nums[k]) { k = j; }
            }
            if (k == i) { return false; }
            i = k;
        }
        
        return i == n-1;     
    }
};

/* Intuition got Optimized */
bool canJump (vector<int>& nums) {
    int n = nums.size(),i=0;

    for (int max_reach = 0; i<n && i<= max_reach; i++) {
        max_reach = max(max_reach,i+nums[i]);
    }

    return i == n;
}

/* TESTER CODE */
int main () {

    Solution* a = new Solution();
    vector<vector<int>> nums ={{2,3,1,1,4},{2,5,0,0},{3,2,1,0,4},{3,0,8,2,0,0,1},{2,0},{0}};
    for (auto i : nums) { cout<<a->canJump(i)<<" "; }

    return 0;
}
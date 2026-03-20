#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/minimum-absolute-difference-in-sliding-submatrix/
// Difficulty : Medium

/* BRUTE FORCE */
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {

        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans;

        for (int i=0;i<=m-k;i++) {
            vector<int> temp;
            for (int j=0;j<=n-k;j++) {
                unordered_set<int> nums;
                for (int x=i;x<i+k;x++) {
                    for (int y=j;y<j+k;y++) {
                        nums.insert(grid[x][y]);
                    }
                }
                if (nums.size() == 1) { temp.push_back(0); }
                else {
                    int min_diff = INT_MAX;
                    for (auto num1 : nums) {
                        for (auto num2 : nums) {
                            if (num1 == num2) { continue; }
                            min_diff = min(min_diff, abs(num1-num2));
                        }
                    }
                    temp.push_back(min_diff);
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};

/* BRUTE FORCE WITH SORTING BASED OPTIMIZATION : SORTING PUTS NUMBERS NEAREST TO OEN ANOTHER BESIDES EACH OTHER ALLOWING US TO ONLY CHECK MINIMUM DISTANCE DIRECTLY. */
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {

        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans;

        for (int i=0;i<=m-k;i++) {
            vector<int> temp;
            for (int j=0;j<=n-k;j++) {
                set<int> nums;
                for (int x=i;x<i+k;x++) {
                    for (int y=j;y<j+k;y++) {
                        nums.insert(grid[x][y]);
                    }
                }
                if (nums.size() == 1) { temp.push_back(0); }
                else {
                    int min_diff = INT_MAX;
                    auto prev_num = nums.begin(), curr = next(nums.begin());
                    while (curr != nums.end()) {
                        min_diff = min(min_diff, abs(*curr - *prev_num));
                        prev_num = curr;
                        curr = next(curr);
                    }
                    temp.push_back(min_diff);
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
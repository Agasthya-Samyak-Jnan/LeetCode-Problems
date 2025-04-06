#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/largest-divisible-subset/
// Difficulty : Medium 

/* 
    - nums[i] % nums[j] == 0 implies "Divisibility" when nums[i] > nums[j], otherwise, mod operation gives nums[i] itself.
      Hence, only first case is useful, So SORT the array in increasing order.
    - "Divisibility" property is transitive in nature => if 'a' divides 'b' and 'b' divides 'c', then  'a' divides 'c'. Use this to build subsets by only checking one pair of number for each number.

*/

/* RECURSION - BACKTRACKING SOLUTION */
class Solution {
    public:
        vector<int> temp, largest, a;
        int n;
    
        void solve(int i) {
            if (i >= n) { return; }
            if (temp.empty() or (a[i] % temp.back()) == 0) {
                temp.push_back(a[i]);
                if (temp.size() > largest.size()) { largest = temp; }
                solve(i+1);
                temp.pop_back();
            }
            solve(i+1);
        }
    
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            
            a = nums;
            n = a.size();
            sort(a.begin(),a.end());
    
            solve(0);
            
            return largest;
        }
};

/* RECURSION ONLY - DYNAMIC PROGRAMMING SOLUTION */
class Solution {
    public:
        vector<int> a;
        int n;
        vector<vector<int>> dp;
    
        vector<int> solve (int i) {
    
            if (i>=n) { return {}; }
    
            vector<int> temp, largest;
    
            for (int j=i+1;j<n;j++) {
                if (a[j] % a[i] == 0) {
                    temp = solve(j);
                    if (temp.size() > largest.size()) { largest = temp; }
                }
            }
    
            largest.insert(largest.begin(),a[i]);
    
            return largest;
        }
    
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            
            a = nums;
            n = a.size();
            dp = vector<vector<int>>(n);
    
            sort(a.begin(),a.end());
    
            vector<int> ans,temp;
    
            for (int i=0;i<n;i++) {
                temp = solve(i);
                if (temp.size() > ans.size()) { ans = temp; }
            }
            
            return ans;
        }
};


/* RECURSION + 1D-MEMOIZATION - DYNAMIC PROGRAMMING SOLUTION */
class Solution {
    public:
        vector<int> a;
        int n;
        vector<vector<int>> dp;
    
        vector<int> solve (int i) {
    
            if (i>=n) { return {}; }
    
            if (!dp[i].empty()) { return dp[i]; }
    
            vector<int> temp, largest;
    
            for (int j=i+1;j<n;j++) {
                if (a[j] % a[i] == 0) {
                    temp = solve(j);
                    if (temp.size() > largest.size()) { largest = temp; }
                }
            }
    
            largest.insert(largest.begin(),a[i]);
    
            return dp[i] = largest;
        }
    
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            
            a = nums;
            n = a.size();
            dp = vector<vector<int>>(n);
    
            sort(a.begin(),a.end());
    
            vector<int> ans,temp;
    
            for (int i=0;i<n;i++) {
                temp = solve(i);
                if (temp.size() > ans.size()) { ans = temp; }
            }
            
            return ans;
        }
};
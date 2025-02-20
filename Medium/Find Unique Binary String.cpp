#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-unique-binary-string/
// Difficulty : Medium

/* HASH TABLE METHOD */
class Solution {
    public:
    
        int binStr_To_Num (string num) {
    
            int n = num.length(), number = 0, bin = 1;
            for (int i=n-1;i>=0;i--) {
                number += num[i] == '1' ? bin : 0;
                bin *= 2;
            }
    
            return number;
        }
    
        string num_To_BinStr (int num, int n) {
    
            string number = "";
            for (int i=0;i<n;i++) {
                if (num&1 == 1) { number = '1' + number; }
                else { number = '0' + number; } 
                num = num>>1;
            }
    
            return number;
        }
    
        string findDifferentBinaryString (vector<string>& nums) {
            
            unordered_set<int> NUMS;
            int n = nums[0].length(), limit = pow(2,n), ans = -1;
    
            for (auto i : nums) { NUMS.insert(binStr_To_Num(i)); }
    
            for (int i=0;i<=limit;i++) {
                if (NUMS.find(i) == NUMS.end()) { ans = i; break; }
            }
    
            return num_To_BinStr(ans,n);
    
        }
    };
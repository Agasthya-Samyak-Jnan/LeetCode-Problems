#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/lemonade-change/
// Difficulty : Easy 

/* GREEDY */
class Solution {
    public:
        bool lemonadeChange(vector<int>& bills) {
    
            if (bills[0] != 5) { return false; }
    
            int n = bills.size();
            unordered_map<int,int> BILLS;
            
            for (int i=0;i<n;i++) {
                if (bills[i] == 10) { 
                    if (BILLS[5] > 0) { BILLS[5]--; }
                    else { return false; }
                }
                else if (bills[i] == 20) {
                    if (BILLS[10] > 0 and BILLS[5] > 0) { BILLS[10]--; BILLS[5]--; }
                    else if (BILLS[5] >= 3) { BILLS[5] -= 3; }
                    else { return false; }
                }
                BILLS[bills[i]]++;
            }
    
            return true;
        }
};
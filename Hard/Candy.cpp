#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/candy/
// DIfficulty : Hard

/* GREEEEEEEEEEEEEEEDY : Time - O(N) , Space - O(N) - Two Pass */
class Solution {
    public:
        int candy(vector<int>& ratings) {
    
            int n = ratings.size();
            vector<int> candy(n,1);
    
            for (int i=0;i<n-1;i++) {
                if (ratings[i] < ratings[i+1]) { candy[i+1] = candy[i] + 1; }
            }
    
            for (int i=n-1;i>0;i--) {
                if (ratings[i-1] > ratings[i] and candy[i-1] <= candy[i]) { 
                    candy[i-1] = candy[i] + 1; 
                }
            }
    
            int candies = 0;
    
            for (auto i : candy) { candies += i; }
    
            return candies;
        }
};

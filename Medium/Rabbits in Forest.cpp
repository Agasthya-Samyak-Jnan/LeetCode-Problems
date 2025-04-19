#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/rabbits-in-forest/
// Difficulty : Medium 

/* GREEDY - FOR MAKING MINIMUM TYPES OF RABBITS - PUTTING MOST POSSIBLE RABBITS INTO ONE TYPE */

/* HASH TABLE + GREEDY + MATH - TWO PASS */
class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            
            unordered_map<int,int> mp;
            int minRabbits = 0;
    
            for (auto num : answers) { mp[num]++; }
    
            for (auto p : mp) {
                int types = p.second/(p.first+1);
                minRabbits += types*(p.first+1);
                p.second -= types*(p.first+1);
                if (p.second > 0) { minRabbits += p.first+1; }
            }
    
            return minRabbits;
        }
};

/* HASH TABLE + GREEDY - ONE PASS */
class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            
            unordered_map<int,int> mp;
            int minRabbits = 0;
    
            for (auto num : answers) {
                if (num == 0) { minRabbits += 1; } // Unique Rabbit
                else if (!mp[num]) { // New Type of rabbit Found.
                    minRabbits += (num+1);
                    mp[num]++;
                }
                else if (mp[num] == num+1) { // Need extra type to fit these same number of rabbits, add a type.
                    minRabbits += (num+1);
                    mp[num] = 1;
                }
                else { mp[num]++; } // Belongs to same type of rabbit.
            }
    
            return minRabbits;
        }
};
#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/partition-labels/
// Difficulty : Medium 

/*
    Two Constraints given in question really makes solving this problem much easier when you observe carefully.

    1. "Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s."
        The above constraint limits our partition process to only substrings, hence makes our task much easier, we need not letters randomly as for subsequences.
    
    2. "each letter appears in at most one part."
        If partitions MUST be Substrings and above condition says each letter should occur only in ONE such partition,
        that implies we MUST make partition long enough to cover the RIGHTMOST occurence of ALL letters in Partition.

    - To know rightmost occurences of each letter before partitioning, we need to do a pass over array and find it out first.
    - Then, you know what to do after reading above. 

*/

/* TWO POINTERS + GREEDY */
class Solution {
    public:
        vector<int> partitionLabels(string s) {
    
            unordered_map<char,int> mp;
            int n = s.length();
            vector<int> ans;
    
            for (int k=0;k<n;k++) { mp[s[k]] = max(mp[s[k]],k); }
            
            int i = 0, j = mp[s[i]], start = 0;
            
            while (i<n) {
                if (mp[s[i]] >= j) { j = mp[s[i]]; }
                if (i == j) { 
                    ans.push_back(i - start + 1); 
                    start = i+1; 
                    if (start < n) { j = mp[s[i+1]]; }
                }
                i++;
            }
            
            return ans;
        }
};
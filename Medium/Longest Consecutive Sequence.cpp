#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/longest-consecutive-sequence/
// Difficulty : Medium 

/* MOST OPTIMAL METHOD : HASH SET + INTUITION */
class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            
            unordered_set<int> HS(nums.begin(),nums.end());
            int max_len = 0;
    
            for (auto num : nums) {
                int n = num, len = 1;
                if (HS.find(n-1) == HS.end()) {
                    while (HS.find(n+1) != HS.end()) { 
                        HS.erase(n);
                        n++; 
                        len++;
                    }
                    max_len = max(max_len,len);
                }
            }
    
            return max_len;
        }
};

/* HASH TABLE + UNION FIND METHOD */

/* CUSTOM UNION FIND TEMPLATE */
template <typename obj>
class UFS {
public:
    // Disjoint Set Data Structures
    unordered_map<obj,obj> parent;
    unordered_map<obj,int> rank;
    unordered_map<obj,int> members;
    int max_members = 1;

    // Initialise Disjoint Set
    UFS () {}

    // Combine/Union thier Families
    void Union (obj a, obj b) {    
        obj A = find(a), B = find(b);
        if (A == B) { return; }
        if (rank[A] > rank[B]) { 
            parent[B] = A;
            members[A] += members[B]; // Merge the Sequence, length is combines length of both sequences.
            max_members = max(max_members,members[A]); // Keep Track of Longest Sequence
        }
        else {
            if (rank[A] == rank[B]) { rank[B]++; }
            parent[A] = B;
            members[B] += members[A]; // Merge the Sequence, length is combines length of both sequences.
            max_members = max(max_members,members[B]); // Keep Track of Longest Sequence
        } 
    }

    // Find Upper-Most Parent 
    obj find (obj a) { 
        if (parent.find(a) == parent.end()) { 
            parent[a] = a; 
            rank[a] = 0;
            members[a] = 1; // Each Sequence starts with itself.
        }        
        return (a == parent[a]) ? a : find(parent[a]); 
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if (nums.empty()) { return 0; }
        
        UFS<int> ufs;
        unordered_map<int,int> mp;

        for (auto num : nums) {
            // Don't Repeat Union operation for duplicate numbers.
            if (mp[num] > 0) { continue; }
            // Merge with previously found Consecutive Numbers
            if (mp[num-1] > 0) { ufs.Union(num,num-1); }
            if (mp[num+1] > 0) { ufs.Union(num,num+1); }
            mp[num]++;
        }

        return ufs.max_members;
    }
};
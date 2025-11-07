#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/count-connected-components-in-lcm-graph/
// Difficulty : Hard

/* GRAPH + UNION FIND + HASH TABLE */
class UFS {
public:
    int n, components;
    unordered_map<int,int> parent, rank;
    unordered_map<int,int> members;

    UFS (vector<int> nums) {
        this->n = nums.size();
        components = n;
        for (auto num : nums) { members[num] = 1; }
    }

    void Union (int a, int b) {
        int A = find(a), B = find(b);
        if (A == B) { return; }
        if (rank[A] > rank[B]) { parent[B] = A; }
        else {
            if (rank[A] == rank[B]) { rank[B]++; }
            parent[A] = B;
        }

        // Number of components decreases only when components of two numbers in 'nums' are merged, not for all multiples of a number.
        if (members[A] and members[B]) { components--; }
    }

    int find (int a) {
        return parent[a] = (parent[a] == a or parent[a] == 0) ? a : find(parent[a]);
    }
};

class Solution {
public:
    int countComponents(vector<int>& nums, int threshold) {

        int n = nums.size();

        UFS ufs(nums);

        // Build a graph by connecting each number to all its multiples less than threshold
        // All multiples should be connected and not just those in 'nums' because, multiples not in 'nums' can also be LCM of any two numbers in 'nums'.
        for (auto num : nums) {
            int k = 2;
            while (num*k <= threshold) {
                ufs.Union(num*k,num);
                k++;
            }
        }
       
        return ufs.components;
    }
};
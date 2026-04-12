#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/path-existence-queries-in-a-graph-i/
// Difficulty : Medium 

/* 
    INTERVALS/SEGMENTS-BASED MODEL OF PROBLEM - SINCE GIVEN NUMS ARRAY IS ALWAYS SORTED, SEGMENTS ARE FORMED AT ELEMENTS WHERE DIFFERENCE GREATER THAN maxDiff. 
    If two elements belong to same segment, they are reachable to each other.
*/
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
        int curr = 0;
        vector<bool> results;

        nums.push_back(nums.back());

        for (int i=0;i<n;i++) {
            int temp = curr;
            if (nums[i+1]-nums[i] > maxDiff) { curr = i+1; }
            nums[i] = temp;
        }

        for (auto q : queries) {
            results.push_back(nums[q[0]] == nums[q[1]]);
        }

        return results;
    }
};

/* 
    USING GRAPH-BASED MODEL OF PROBLEM AND UNION FIND DATA STRUCTURE. 
    Elements that are less than maxDiff difference from each other form a chain or component. Many such components are formed.
    If two elements belong to same component they are reachable to each other.
*/
class UFS {
public:
    int n;
    vector<int> parent, rank;

    UFS (int n) {
        this->n = n;
        parent = vector<int>(n);
        rank = vector<int>(n,0);
        iota(parent.begin(),parent.end(),0);
    }

    void Union (int a, int b) {
        int A = find(a), B = find(b);
        if (A == B) { return; }
        if (rank[B] < rank[A]) { parent[B] = A; }
        else {
            if (rank[A] == rank[B]) { rank[B]++; }
            parent[A] = B;
        }
    }

    int find (int a) {
        return parent[a] = (parent[a] == a) ? a : find(parent[a]);
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
        UFS ufs(n);
        vector<bool> results;

        for (int i=0;i<n-1;i++) {
            if (nums[i+1]-nums[i] <= maxDiff) { ufs.Union(i,i+1); }
        }

        for (auto q : queries) {
            results.push_back(ufs.find(q[0]) == ufs.find(q[1])); 
        }

        return results;
    }
};
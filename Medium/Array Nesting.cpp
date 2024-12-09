#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/array-nesting/
// Difficulty : Medium 

/* DEPTH-FIRST SEARCH BASED SOLUTION */
class Solution {
public:
    vector<int> nums,visited;
    
    int dfs (int i) {
        if (visited[i]) { return 0; }
        visited[i] = 1;
        return 1 + dfs(nums[i]);
    }
    
    int arrayNesting(vector<int>& nums) {
        
        int n = nums.size(), ans = 0;
        this->nums = nums;
        visited = vector<int>(n,0);
        
        for (int i=0;i<n;i++) {
            if (!visited[i]) { ans = max(ans,dfs(i)); }
        }
        
        return ans;
    }
};

/* UNION-FIND BASED SOLUTION */
class UFS {
public:
    int maxDisciples;
    vector<int> parent,disciples;

    UFS (int n) {
        maxDisciples = 1;
        parent = vector<int>(n);
        disciples = vector<int>(n,1);
        iota(parent.begin(),parent.end(),0);
    }

    void Union (int a, int b) {  
        int A = find(a), B = find(b);
        if (A == B) { return; }
        parent[B] = A; 
        disciples[A] += disciples[B];
        maxDisciples = max(maxDisciples,disciples[A]);
    }

    int find (int a) {  
        return (a == parent[a]) ? a : parent[a] = find(parent[a]);
    }
};

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        
        int n = nums.size();
        UFS ufs(n);
        
        for (int i=0;i<n;i++) { ufs.Union(nums[i],i); }
        
        return ufs.maxDisciples;
    }
};

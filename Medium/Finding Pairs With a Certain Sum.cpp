#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/finding-pairs-with-a-certain-sum/
// Difficulty : Medium 

/* HOW TO USE HASH TABLE IN A GOOD WAY */
class FindSumPairs {
public:

    vector<int> n1, n2;
    unordered_map<int,int> m2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        for (auto num : n2) { m2[num]++; }
    }
    
    void add(int index, int val) {
        m2[n2[index]]--;
        n2[index] += val;
        m2[n2[index]]++;
    }
    
    int count(int tot) {
        int cnt = 0;
        for (auto num : n1) { cnt += m2[tot-num]; }
        return cnt;
    }
};
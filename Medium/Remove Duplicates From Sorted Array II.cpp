#include<bits/stdc++.h>

using namespace std;

// Link to the Problem: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// Difficulty: Medium

/* My Initial Intuition : Time Complexity (O(n+j)) (2ms Runtime) */
class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int i=0, j=0, n = a.size();
        map<int,int> num;
        
        for (i=0;i<n;i++) {
            num[a[i]] += 1;
        }
        
        for (auto i=num.begin();i!=num.end();i++) {
            int k=2;
            while (i->second>0 && k>0) {
                a[j] = i->first;
                i->second--;j++;k--;
            }
        }
        return j;
    }
};

/* Best Solution : Time Complexity (O(n-2)) (0ms Runtime) */
class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int n = a.size();
        if (n<=2) { return n; }
        int j = 1;
        for (int i=2;i<n;i++) {
            if (a[j-1] != a[i]) { a[++j] = a[i]; }
        }
        
        return ++j;
    }
};
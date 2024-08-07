#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/kth-largest-element-in-a-stream/
// Difficulty : Easy

/* THIS NEEDS FURTHER IMPROVEMENT THIS SOLUTION IS JUST OUTLINE IDEA OF THE LOGIC NEEDED */
class KthLargest {
public:
    vector<int> q;
    int k;
    
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        q = nums;
        sort(q.begin(),q.end(),greater<int>());
    }
    
    int add(int val) {
        int i;
        for (i=0;i<q.size()&&q[i]>val;i++) {}
        q.insert(q.begin()+i,val);
        return q[k-1];
    }
};

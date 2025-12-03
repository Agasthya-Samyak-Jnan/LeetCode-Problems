#include <bits/stdc++.h>

// Link to the Problem: https://leetcode.com/problems/design-exam-scores-tracker/
// Difficulty: Medium

using namespace std;

/* DYNAMIC SEGMENT TREE BASED SOLUTION FOR OPTIMIZING SUM QUERY AND ADDITION OF VALUES (O(logN) sum, O(logN) add) */

class DST {
public:
    DST () { val = 0; left = right = nullptr; }

    void add (int time, int value) { update(this,range_l,range_r,time,value); }
    long long Sum (int left, int right) { return sum(this,left,right,range_l,range_r); }

private:
    static const int range_l = 0, range_r = 1e9;
    long long val;
    DST* left, *right;

    /* To find Range Sum */
    long long sum (DST* root, int left, int right, int start, int end) {
        if (right < start or left > end) { return 0; }
        if (left <= start and end <= right) { return root->val; }
        int mid = (start+end)/2;
        long long s = 0;
        s += (root->left) ? sum(root->left,left,right,start,mid) : 0;
        s += (root->right) ? sum(root->right,left,right,mid+1,end) : 0;
        return s;
    }

    /* To add a Number to DST */
    void update (DST* root, int start, int end, int time, int value) {
        if (start == end) {  
            root->val = value; 
            return;
        }
        int mid = (start+end)/2;
        if (time <= mid) {
            if (!root->left) { root->left = new DST(); } 
            update(root->left,start,mid,time,value); 
        }
        else { 
            if (!root->right) { root->right = new DST(); }
            update(root->right,mid+1,end,time,value); 
        }
        root->val = (root->left ? root->left->val : 0) + (root->right ? root->right->val : 0);
    }
};

class ExamTracker {
public:

    DST dst;

    ExamTracker () {}    
    
    void record(int time, int score) {
        dst.add(time,score);
    }
    
    long long totalScore(int startTime, int endTime) {
        return dst.Sum(startTime,endTime);
    }
};
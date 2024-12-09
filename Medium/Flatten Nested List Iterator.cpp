#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/flatten-nested-list-iterator/
// Difficulty : Medium 

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

/* DEPTH-FIRST SEARCH + QUEUE - ANALOGY : TRY TO DRAW THE NESTED LIST AS A TREE WHERE EACH LIST HAS INTEGERS AS CHILD NODES , YOU WILL UNDERSTAND THE SOLUTION */
class NestedIterator {
public:
    queue<int> q;
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
    }
    
    void dfs (vector<NestedInteger>& List) {
        int n = List.size();
        for (int i=0;i<n;i++) {
            if (List[i].isInteger()) { q.push(List[i].getInteger()); }
            else { dfs(List[i].getList()); }
        }
    }
    
    int next() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    bool hasNext() {
        return !q.empty();
    }
};
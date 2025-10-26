#include <bits/stdc++.h>

// Link to the Problem: https://leetcode.com/problems/smallest-number-in-infinite-set/
// Difficulty: Medium

using namespace std; 

/* PRIORITY QUEUE (MIN HEAP) and HASH SET */
/* When you remove a number, you always remove smallest, and keep moving forward. (When you only keep removing smallest) */
/* When you start adding back, you will have to see if number you have reached to right now is smaller than added back number, because added numbers could be smaller than your current number.*/
class SmallestInfiniteSet {
public:
    int i = 1;
    unordered_set<int> removed;
    priority_queue<int,vector<int>,greater<int>> addedBackHeap;

    SmallestInfiniteSet() {}
    
    int popSmallest() {
        if (!addedBackHeap.empty() and i > addedBackHeap.top()) {
            int num = addedBackHeap.top(); addedBackHeap.pop();
            removed.insert(num);
            return num;
        }
        removed.insert(i);
        return i++; 
    }
    
    void addBack(int num) {
        if (removed.find(num) != removed.end()) {
            addedBackHeap.push(num);
            removed.erase(num);
        }
    }
};
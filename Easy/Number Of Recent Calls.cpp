#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/number-of-recent-calls/
// Difficulty : Easy

/* Design Problem Using Queue - Read Problem Description to know why Queue is Used */
class RecentCounter {
public:
    int counter;
    queue<int> requests;
    RecentCounter() {
        counter = 0;
    }
    /* Remove Requests Older than 3000ms from current requests. In queue, FIRST IN - FIRST OUT, FIRST REQUEST - OLDEST REQUEST */
    int ping(int t) {
        requests.push(t);
        while (requests.front() < t-3000) { requests.pop(); }
        return requests.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/seat-reservation-manager/
// Difficulty : Medium 

/* ORDERED-SET SOLUTION (SLOWER) */
class SeatManager {
public:
    set<int> unreserved;
    
    SeatManager(int n) {
        for (int i=1;i<=n;i++) { unreserved.insert(i); }
    }
    
    int reserve() {
        int seat = *unreserved.begin();
        unreserved.erase(seat);
        return seat;
    }
    
    void unreserve(int seat) {
        unreserved.insert(seat);
    }
};


/* PRIORITY QUEUE - HEAP SOLUTION (FASTER THAN PREVIOUS) */
class SeatManager {
public:
    priority_queue<int,vector<int>,greater<int>> unreserved;
    
    SeatManager(int n) {
        for (int i=1;i<=n;i++) { unreserved.push(i); }
    }
    
    int reserve() {
        int seat = unreserved.top(); unreserved.pop();
        return seat;
    }
    
    void unreserve(int seat) {
        unreserved.push(seat);
    }
};

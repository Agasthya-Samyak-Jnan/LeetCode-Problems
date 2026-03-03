#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/design-ride-sharing-system/
// Difficulty : Medium 

/* QUEUES + HASH SET */
class RideSharingSystem {
public:

    queue<int> riderQ, driverQ; // waiting queues
    unordered_set<int> riders;

    RideSharingSystem() {}
    
    void addRider(int riderId) {
        // Add the new rider to the system
        riderQ.push(riderId);
        riders.insert(riderId);
    }
    
    void addDriver(int driverId) {
        // Add the new driver to the system
        driverQ.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        // If there are no drivers available
        if (driverQ.empty()) { return {-1,-1}; }
        // Remove all riders who cancelled ride before selecting earliest requesting rider
        while (!riderQ.empty() and riders.find(riderQ.front()) == riders.end()) { riderQ.pop(); }
        // If there are riders requesting a ride
        if (riderQ.empty()) { return {-1,-1}; }
        // Match the current driver and rider in waiting queues
        int driver = driverQ.front(), rider = riderQ.front();
        // Remove matched rider and driver from waiting queues
        driverQ.pop();
        riderQ.pop();
        riders.erase(rider);
        // return the matched result
        return {driver,rider}; 
    }
    
    void cancelRider(int riderId) {
        // cancel the ride by removing rider from the system
        riders.erase(riderId);
    }
};
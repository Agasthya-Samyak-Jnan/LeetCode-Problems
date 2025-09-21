#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/implement-router/
// Difficulty : Medium


/* QUEUE + SEGMENT TREE + HASH TABLE BASED SOLUTION - All Queries in Logarithimic Time - 2nd Solution is Most Optimized */
/* 
    Dynamic Segment Tree API 
    - Works on Given Domain of Numbers, 
    - dynamically allocates memory for new numbers as required, 
    - Supports Addition/Removal of Numbers 
*/
class DST {
public:
    DST () { freq = 0; left = right = nullptr; }
    void add (int value) { update(this,range_l,range_r,value,1); }
    void erase (int value) { update(this,range_l,range_r,value,-1); }
    int Count (int left, int right) { return count(this,left,right,range_l,range_r); }

private:
    static const int range_l = 0, range_r = 1e9;
    int freq;
    DST* left, *right;

    /* To find Count of Numbers in a Range (including duplicates) */
    int count (DST* root, int left, int right, int start, int end) {
        if (right < start or left > end) { return 0; }
        if (left <= start and end <= right) { return root->freq; }
        int mid = (start+end)/2, c = 0;
        c += (root->left) ? count(root->left,left,right,start,mid) : 0;
        c += (root->right) ? count(root->right,left,right,mid+1,end) : 0;
        return c;
    }

    /* To add/remove a Number from DST */
    void update (DST* root, int start, int end, int value, int flag) { // flag = +1 -> add, flag = -1 -> remove
        if (start == end) {  
            root->freq += (flag == 1 ? 1 : -1); 
            return;
        }
        int mid = (start+end)/2;
        if (value <= mid) {
            if (!root->left) { root->left = new DST(); } 
            update(root->left,start,mid,value,flag); 
        }
        else { 
            if (!root->right) { root->right = new DST(); }
            update(root->right,mid+1,end,value,flag); 
        }

        root->freq = (root->left ? root->left->freq : 0) + (root->right ? root->right->freq : 0);
    }
};

class Router {
public:

    int limit;
    queue<vector<int>> q;
    unordered_map<string,int> packets; 
    unordered_map<int,DST> time_dest_packs;

    Router(int memoryLimit) { limit = memoryLimit; }

    // Converts a Packet to String (A method of hashing a Packet)
    string PacketHash (int src, int dest, int time) {
        return to_string(src) + "," + to_string(dest) + "," + to_string(time);
    }
    
    bool addPacket(int source, int destination, int timestamp) {

        // Duplicate
        if (packets[PacketHash(source,destination,timestamp)] != 0) { return false; }

        // Out of Memory
        if (q.size() >= limit) { forwardPacket(); }

        // No issues
        q.push({source,destination,timestamp});
        time_dest_packs[destination].add(timestamp);
        packets[PacketHash(source,destination,timestamp)] = 1;

        return true;
    }
    
    vector<int> forwardPacket() {

        // When there are No Packets in Router 
        if (q.size() == 0) { return {}; }

        // When there are Packets in Router
        vector<int> p = q.front(); q.pop(); 
        packets[PacketHash(p[0],p[1],p[2])] = 0;
        time_dest_packs[p[1]].erase(p[2]); // p[1] = destination, p[2] = timestamp

        return p;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        return time_dest_packs[destination].Count(startTime,endTime);
    }
};

 /* 
    Hashing for checking if a packet is duplicate is optimised by using an unordered_set and 64-bit Numbers as identifiers,
    instead of strings. Saved Space and Time on int-to-string conversion and memory allocation for string.
    ~750ms optimized to ~490ms time, ~538mb to ~524mb space.
*/
/* Same DST Class was used here as well */
class Router {
public:

    int limit;
    queue<vector<int>> q;
    unordered_set<uint64_t> packets;  // unordered_set and 64-bits Number packet identifier
    unordered_map<int,DST> time_dest_packs;

    Router(int memoryLimit) { limit = memoryLimit; }

    // Converts a Packet to 64-bit Integer to use less storage and time to detect duplicates. (A method of hashing a Packet)
    uint64_t PacketHash (uint64_t src, uint64_t dest, uint64_t time) {
        return ((src<<47)|(dest<<30)|time);
    }
    
    bool addPacket(int source, int destination, int timestamp) {

        // Duplicate
        if (packets.find(PacketHash(source,destination,timestamp)) != packets.end()) { return false; } // unordered_set and 64-bits Number packet identifier

        // Out of Memory
        if (q.size() >= limit) { forwardPacket(); }

        // No issues
        q.push({source,destination,timestamp});
        time_dest_packs[destination].add(timestamp);
        packets.insert(PacketHash(source,destination,timestamp)); // unordered_set and 64-bits Number packet identifier

        return true;
    }
    
    vector<int> forwardPacket() {

        // When there are No Packets in Router 
        if (q.size() == 0) { return {}; }

        // When there are Packets in Router
        vector<int> p = q.front(); q.pop(); 
        packets.erase(PacketHash(p[0],p[1],p[2])); // unordered_set and 64-bits Number packet identifier
        time_dest_packs[p[1]].erase(p[2]); // p[1] = destination, p[2] = timestamp

        return p;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        return time_dest_packs[destination].Count(startTime,endTime);
    }
};

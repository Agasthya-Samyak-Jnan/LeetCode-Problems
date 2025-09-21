#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/implement-router/
// Difficulty : Medium


/* QUEUE + SEGMENT TREE + HASH TABLE BASED SOLUTION - All Queries in Logarithimic Time */
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

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
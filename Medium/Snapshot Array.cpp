#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/snapshot-array/
// Difficulty : Medium


/* SYSTEM DESIGN + BINARY SEARCH (LOGIC SKILL) - 110ms, 202MB */
class SnapshotArray {
public:
    const int INF = 100000;
    int snap_id = 0;
    // Store multiple snaps as an Interval (i call it as snap_object/version_object) = {snap_start,snap_end,value at index during those snaps}
    vector<vector<vector<int>>> arr; 

    SnapshotArray(int length) {
        int n = length;
        arr = vector<vector<vector<int>>>(n, vector<vector<int>>(1, {0,INF,0}));
    }
    
    /* O(1) Time, NO/O(1) Space per Set Operation */
    void set(int index, int val) {
        if (arr[index].back()[2] == val) { return; }
        if (arr[index].back()[0] == snap_id) { arr[index].back()[2] = val; return; }
        arr[index].back()[1] = snap_id-1;
        arr[index].push_back({snap_id,INF,val});
    }
    
    /* O(1) Time, No Space per snap() Operation */
    int snap() {
        return snap_id++;
    }
    
    // Binary Search the Interval (or Version) that covers given snap_id and return the value in that Version.
    /* O(logK) Time , where  K = no.of.unique snaps of array or no.of.intervals, O(1) Space per get() Operation */
    int get(int index, int snap_id) {
        // arr[index][x][0] = snap_start, arr[index][x][1] = snap_end, arr[index][x][2] = value
        int low = 0, high = arr[index].size(), mid;

        while (low <= high) {
            mid = (low+high)/2;
            if (arr[index][mid][0] <= snap_id and snap_id <= arr[index][mid][1]) {
                return arr[index][mid][2];
            } 
            else if (snap_id < arr[index][mid][0]) { high = mid-1; }
            else { low = mid+1; }
        }

        return -1;
    }
};

/* ABOVE SOLUTION, BUT PERFECTLY OPTMIZED FOR TIME AND SPACE EFFICIENCY (IMPLEMENTATION SKILL) - 75ms, 184MB */
class SnapshotArray {
public:
    int snap_id = 0;
    vector<vector<pair<int,int>>> arr; // snap_obj = {snap_start,snap_end,value at index}

    SnapshotArray(int length) {
        arr = vector<vector<pair<int,int>>>(length,vector<pair<int,int>>(1,{0,0}));
    }
    
    void set(int index, int val) {
        if (arr[index].back().second == val) { return; }
        if (arr[index].back().first == snap_id) { arr[index].back().second = val; return; }
        arr[index].push_back({snap_id,val});
    }
    
    int snap() {
        return snap_id++;
    }
    
    // Binary Search the Interval (or Version) that covers given snap_id and return the value in that Version.
    int get(int index, int snap_id) {
        // arr[index][x][0] = snap_start, arr[index][x][1] = value
        int low = 0, high = arr[index].size()-1, mid;
        auto &arr_idx = arr[index];

        while (low <= high) {
            mid = (low+high)/2;
            if (snap_id >= arr_idx[mid].first) { low = mid+1; } 
            else { high = mid-1; }
        }

        return arr_idx[high].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/lru-cache/
// Difficulty : Medium 

/* DOUBLY-LINKED LIST MAPPED TO KEYS USING HASH TABLE - DESIGN PROBLEM */

class LRUCache {
public:
    int cap;
    // Map the List Nodes containing Keys to thier Keys in Hash Table tagged with thier values.
    unordered_map<int,pair<int,list<int>::iterator>> cmp;
    list<int> keys;
    
    // Set Capacity
    LRUCache(int capacity) { cap = capacity; }
    
    int get(int key) {
        // If Key-Value pair exists in Cache List "keys",
        if (cmp.find(key) != cmp.end()) {
            // Remove that key which is somewhere in Cache List "keys" and put it at beginning.
            // The RightMOST keys represent Least Recently Used Keys.
            // The LeftMOST keys represent Most Recently Used Keys.
            keys.erase(cmp[key].second);
            keys.push_front(key);
            
            // Save the new position of this existing key in the List to Hash Table.
            cmp[key].second = keys.begin();
            
            // Give the Value paired with Key.
            return cmp[key].first;    
        }
        // If Key-Value pair doesn't exist.
        return -1;
    }
    
    void put(int key, int value) {
        
        // If Key-Value pair exists in Cache List "keys",
        if (cmp.find(key) != cmp.end()) {
            cmp[key].first = value;
            keys.erase(cmp[key].second);
            keys.push_front(key);
            cmp[key].second = keys.begin();
        }
        
        // If Key-Value pair doesn't exist.
        else { 
            // Remove Least Recently Used Key from cache List "keys" - RightMOST node of the List.
            if (keys.size() == cap) {
                cmp.erase(keys.back());
                keys.pop_back();   
            }
            
            // Add the new Key-Value Pair to the beginning as its freshly used just now. (Most Recent are LeftMOST nodes in List)
            cmp[key].first = value;
            keys.push_front(key);
            cmp[key].second = keys.begin();   
        }
    }
};
#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/design-hashmap/
// Difficulty : Easy

class MyHashMap {
public:
    int mp[1000001];
    MyHashMap() {
        memset(mp,-1,sizeof(mp));
    }
    
    void put(int key, int value) {
         mp[key] = value;
    }
    
    int get(int key) {
        return mp[key];
    }
    
    void remove(int key) {
         mp[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
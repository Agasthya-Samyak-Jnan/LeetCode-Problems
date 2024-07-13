#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/design-hashset/
// Difficulty : Easy

/* Actual Inner Working Solution */
class MyHashSet {
public:
    vector<int> set;
    MyHashSet() {        
    }
    
    void add(int key) {
         auto it = find(set.begin(),set.end(),key);
         if (it == set.end()) { set.push_back(key); }
    }
    
    void remove(int key) {
         auto it = find(set.begin(),set.end(),key);
         if (it != set.end()) { set.erase(it); }
    }
    
    bool contains(int key) {
         return find(set.begin(),set.end(),key) != set.end();
    }
};

/* Scam Solution : Constraint-Known HashSet */
class MyHashSet {
public:
    int set[1000001];
    MyHashSet() {
        memset(set,0,sizeof(set));
    }
    
    void add(int key) {
         set[key] = 1;
    }
    
    void remove(int key) {
         set[key] = 0;
    }
    
    bool contains(int key) {
         return set[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
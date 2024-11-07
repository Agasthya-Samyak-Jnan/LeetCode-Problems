#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/insert-delete-getrandom-o1/
// Difficulty : Medium 

/* HASH TABLE METHOD */

/* TIME OPTIMIZED SOLUTION */
class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int,int> indexOf;
    int n;
    
    RandomizedSet() {
        n = 0;
        srand(time(nullptr));
    }
    
    bool insert(int val) {
        if (!indexOf.count(val)) {
            indexOf[val] = n;
            nums.push_back(val);
            n++;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if (indexOf.count(val) != 0) {
            
            nums[indexOf[val]] = nums[n-1];
            indexOf[nums[indexOf[val]]] = indexOf[val];
            
            indexOf.erase(val);
            nums.pop_back();
            n--;
            
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return nums[rand()%n];
    }
};

/* SPACE OPTIMIZED SOLUTION */
class RandomizedSet {
public:
    unordered_set<int> nums;
    int n;
    
    RandomizedSet() {
        n = 0;
        srand(time(nullptr));
    }
    
    bool insert(int val) {
        if (nums.find(val) == nums.end()) {
            nums.insert(val);
            n++;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if (nums.find(val) != nums.end()) {
            nums.erase(val);
            n--;
            return true;
        }
        return false;
    }
    
    int getRandom() {
        auto it = nums.begin();
        advance(it,rand()%n);
        return *it;
    }
};
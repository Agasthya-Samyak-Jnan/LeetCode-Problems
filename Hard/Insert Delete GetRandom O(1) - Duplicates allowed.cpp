#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/
// Difficulty : Hard

/* 
    HASH TABLE METHOD - VERY SIMILAR TO : Question 380 - Insert Delete GetRandom O(1) (Medium) 
    Here, instead of just storing a single index for a value, we store a set of indices for keeping index for each duplicate of it, 
    since duplicates are allowed.
*/

/* 
   TIME OPTIMIZED SOLUTION  
   Swap value to be removed with last value in the array. 
   Easy O(1) Time Removals. 
   Easy O(1) Time Random Access.
   Easy O(1) Time Inserts.
   O(N*K) Space, N = Number of Unique Values, K = Number of Duplicates of each Value.
*/ 
class RandomizedCollection {
public:
    vector<int> nums;
    unordered_map<int,unordered_set<int>> indexOf; // Value TO Set of Positions/Indices it is present in Array | Value -> {idx1, idx2 ... idxN}

    RandomizedCollection() {
        srand(time(nullptr));
    }
    
    bool insert(int val) {
        bool result = indexOf[val].empty();
        indexOf[val].insert(nums.size());
        nums.push_back(val);
        return result;
    }
    
    bool remove(int val) {

        // Number doesn't exist in number array, can't remove.
        if (indexOf[val].empty()) { return false; }

        int idx = *indexOf[val].begin(); // Pick any one copy at any index out of many copies of 'val'.
        int lastIdx = nums.size() - 1; // The current last position of our number array.
        int lastVal = nums[lastIdx]; // The value at current last position.
        
        // If value to be removed is at end of number array, just pop it out.
        if (val == lastVal) { 
            indexOf[val].erase(lastIdx); // Since it was the last value, remove (size-1) index from its set of indices.
            nums.pop_back(); // Remove it from Number Storage Array
            return true;
        }

        nums[idx] = lastVal; // Assign Last Number to Removed Number's Position.
        indexOf[lastVal].erase(lastIdx); // Remove Last Position Entry in Last Number's Indices Set.
        indexOf[lastVal].insert(idx); // Add New Assigned Position Index to re-assigned Last Number.

        indexOf[val].erase(idx); // Since 'val' from 'idx' index was removed, remove 'idx' from its set of Indices.
        nums.pop_back(); // Remove it from Number Storage Array

        return true;
    }
    
    int getRandom() {
        return nums[rand()%(nums.size())];
    }
};

/* 
   SPACE OPTIMIZED SOLUTION - unordered_multiset
   Hash Based Containers can't provide direct random access, since there is no fixed position for elements stored in it,
   since rehashing keeps occuring while inserting and removing elements. 
   O(1) Time Removals.
   O(R) Time Random Access. (0 <= R <= Size of Array).
   O(1) Time Inserts.
   O(N) Space, N = Number of Values Present including Duplicates.
*/
class RandomizedCollection {
public:
    unordered_multiset<int> nums;
    
    RandomizedCollection () {
        srand(time(nullptr));
    }
    
    bool insert(int val) {
        bool existed = (nums.find(val) == nums.end());
        nums.insert(val);
        return existed;
    }
    
    bool remove(int val) {
        auto it = nums.find(val);
        if (it != nums.end()) {
            nums.erase(it);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        auto it = nums.begin();
        advance(it,rand()%nums.size());
        return *it;
    }
};
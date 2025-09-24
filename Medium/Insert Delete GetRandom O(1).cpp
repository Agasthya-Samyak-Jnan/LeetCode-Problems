#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/insert-delete-getrandom-o1/
// Difficulty : Medium 

/* HASH TABLE METHOD */

/* 
   TIME OPTIMIZED SOLUTION - unordered_map
   Swap value to be removed with last value in the array. 
   Easy O(1) Time Removals. 
   Easy O(1) Time Random Access.
   Easy O(1) Time Inserts.
   O(2N) Space, N = Number of Unique Values.
*/ 
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

/* 
   SPACE OPTIMIZED SOLUTION - unordered_set
   Hash Based Containers can't provide direct random access, since there is no fixed position for elements stored in it,
   since rehashing keeps occuring while inserting and removing elements. 
   O(1) Time Removals.
   O(R) Time Random Access. (0 <= R <= Size of Array).
   O(1) Time Inserts.
   O(N) Space, N = Number of Unique Values.
*/
class RandomizedSet {
public:
    unordered_set<int> nums;
    
    RandomizedSet() {
        srand(time(nullptr));
    }
    
    bool insert(int val) {
        if (nums.find(val) == nums.end()) {
            nums.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if (nums.find(val) != nums.end()) {
            nums.erase(val);
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

/* 
   SPACE OPTIMIZED SOLUTION - unordered_set
   Hash Based Containers can't provide direct random access, since there is no fixed position for elements stored in it,
   since rehashing keeps occuring while inserting and removing elements. 
   O(1) Time Removals.
   O(R) Time Random Access. (0 <= R <= Size of Array).
   O(1) Time Inserts.
   O(N) Space, N = Number of Unique Values.
*/
#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/design-a-number-container-system/
// Difficulty : Medium 

/* HASH TABLE + BST-BASED SET */
class NumberContainers {
    public:
        unordered_map<int,int> idx_num;
        unordered_map<int,set<int>> num_idx;
    
        NumberContainers() {}
        
        // TC : O(logN + logM + 1) : N = number of indices in idx_num[index], M = number of indices in num_idx[number] at the moment.
        void change(int index, int number) {
            if (idx_num[index]) { num_idx[idx_num[index]].erase(index); }
            idx_num[index] = number;
            num_idx[number].insert(index);
        }
        
        // TC : O(1)
        int find(int number) {
            int idx = *num_idx[number].begin();
            return idx == 0 ? -1 : idx;
        }
};

/* PYTHON3 SOLUTION 

from sortedcontainers import SortedSet

class NumberContainers:
    
    def __init__(self):
        self.idx_to_num  = defaultdict(int)
        self.num_to_idx = defaultdict(SortedSet)
    
    def change(self, index: int, number: int) -> None:
        if self.idx_to_num[index] != 0 :
            self.num_to_idx[self.idx_to_num[index]].discard(index)
        self.idx_to_num[index] = number
        self.num_to_idx[number].add(index)
            
    
    def find(self, number: int) -> int:
        if number in self.num_to_idx and self.num_to_idx[number]:
            return self.num_to_idx[number][0]
        return -1
        
*/
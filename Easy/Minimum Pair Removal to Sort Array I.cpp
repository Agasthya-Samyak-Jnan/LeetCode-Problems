#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/
// Difficulty : Easy

/* PRIORITY QUEUE (MIN HEAP) + HASH TABLE + LINKED LIST + SIMULATION */
class Solution {
    public:
        int minimumPairRemoval(vector<int>& nums) {
            
            unordered_map<int,list<vector<int>>::iterator> listnode;
            list<vector<int>> a;
            int n = nums.size(), minOps = 0;
    
            for (int i=0;i<n;i++) { a.push_back({i,nums[i]}); }
    
            while (a.size() > 1) {
    
                // Check if Sorted.
                bool sorted = true;
                (*a.begin())[0] = 0;
                listnode[0] = a.begin();
                int i = 1;
    
                for (auto it=next(a.begin(),1);it!=a.end();it++) {
    
                    int curr = (*it)[1], prev = (*next(it,-1))[1];
    
                    if (prev > curr) { sorted = false; }
    
                    listnode[i] = it;
                    (*it)[0] = i;
                    i++;
                }
    
                if (sorted) { break; }
    
                // Push all adjacent pair sums to a Min Heap.
                priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq; // Min Heap
    
                for (auto it=next(a.begin(),1);it!=a.end();it++) {
                    int curr = (*it)[1], prev = (*next(it,-1))[1], index = (*it)[0];
                    pq.push({prev+curr,index-1});
                }
    
                // Get Minimum Leftmost Adjacent Pair Sum and its location.
                int index = pq.top()[1], sum = pq.top()[0];
    
                // Replace the pair with thier sum in the list.
                auto it = listnode[index]; // type = list<pair<int,int>>::iterator
    
                it = a.insert(it,{index,sum}); // Pointer to new inserted 'sum' node.
                it = next(it,1);
                it = a.erase(it); // Erase first element in pair and get pointer to second element of pair.
                a.erase(it); // Erase second element of pair.
    
                // We performed 1 Operation now.
                minOps++;
            }
            
            return minOps;
        }
};
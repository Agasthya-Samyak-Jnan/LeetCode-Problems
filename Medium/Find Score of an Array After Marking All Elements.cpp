#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/
// Difficulty : Medium 

/* PRIORITY QUEUE - MIN HEAP METHOD */
class Solution {
public:
    long long findScore(vector<int>& nums) {
        
        long long n = nums.size(), score = 0, curr, pos;
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        vector<int> visited(n,0);
        
        for (int i=0;i<n;i++) { pq.push({nums[i],i}); }
        
        while (!pq.empty()) {
            
            curr = pq.top().first;
            pos = pq.top().second;
            pq.pop();
            
            if (visited[pos]) { continue; }
            
            score += curr;
            visited[pos] = 1;
            if (pos-1 >= 0) { visited[pos-1] = 1; }
            if (pos+1 < n) { visited[pos+1] = 1; }
        }
        
        return score;
    }
};

/* 

PYTHON3 VERSION OF ABOVE SOLUTION 

import heapq

class Solution:
    def findScore(self, nums: List[int]) -> int:
        
        n = len(nums)
        visited = [0]*n
        pq = []
        score = 0
        
        for i in range(n) :
            heapq.heappush(pq,[nums[i],i])
            
        while pq:
            
            curr = pq[0][0]
            pos = pq[0][1]
            heapq.heappop(pq)
            
            if visited[pos] : 
                continue
            
            score += curr
            visited[pos] = 1
            if pos-1 >= 0 :
                visited[pos-1] = 1
            if pos+1 < n :
                visited[pos+1] = 1
        
        return score
    
*/
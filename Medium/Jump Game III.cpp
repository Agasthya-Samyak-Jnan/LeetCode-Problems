#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/jump-game-iii/
// Difficulty : Medium

/* DEPTH-FIRST SEARCH ON ARRAYS WHILE REMANINING IN-BOUNDS */
class Solution {
public:
    int n;
    vector<int> visited;
    
    bool search (vector<int>& arr, int i) {
         if (i<0 || i>=n || visited[i]) { return false; }
         visited[i] = 1;
         return arr[i] == 0 || search(arr,i+arr[i]) || search(arr,i-arr[i]);
    }
    
    bool canReach(vector<int>& arr, int start) {
        
        n = arr.size();
        visited = vector<int>(n,0);
        return search(arr,start);

    }
};

/* BREADTH-FIRST SEARCH ON ARRAYS WHILE REMAINING IN-BOUNDS */
class Solution {
public:
    int n;
    vector<int> visited;
    
    bool search (vector<int>& arr, int i) {
        
        queue<int> q;
        q.push(i);
        
        while (!q.empty()) {
            
            i = q.front(); q.pop();
            visited[i] = 1;
            
            if (arr[i] == 0) { return true; }
            
            if (i+arr[i] < n && !visited[i+arr[i]]) { q.push(i+arr[i]); }
            if (i-arr[i] >= 0 && !visited[i-arr[i]]) { q.push(i-arr[i]); }
        }
        
        return false; 
    }
    
    bool canReach(vector<int>& arr, int start) {
        
        n = arr.size();
        visited = vector<int>(n,0);
        return search(arr,start);
                
    }
};

/* Comment Out one of the two solutions before running tester. */

/* TESTER CODE */
int main () {

    Solution* a = new Solution();
    vector<int> nums = {4,2,9,0,9,1,2};
    int start = 5;
    cout<<a->canReach(nums,start);

    return 0;
}
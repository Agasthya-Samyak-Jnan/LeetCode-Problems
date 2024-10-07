#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/simplify-path/
// Difficulty : Medium 

/* DEQUE (QUEUE AND STACK BEHAVIOURS TOGETHER) + STRING MANIPULATIONS */
class Solution {
public:
    int n,i;
    
    // Get Directory Name Properly by ignoring '/'
    string parse_directory (int& i, string& path) {
        int j=i;
        while (path[i] != '/' && i<n) { i++; }
        return path.substr(j,i-j);
    }
    
    string simplifyPath(string path) {
        
        // Deque for using as both 'queue' and 'stack'
        deque<string> q;
        string ans = "/", temp;
        n = path.length();
        i=0;
        
        while (i<n) {
            
            while (path[i] == '/') { i++; }
            temp = parse_directory(i,path);
            
            // Stack Mode : Whenever you find ".." (Link to Parent),
            // Go to one level higher directory by popping current directory.
            if (temp == "..") { 
                if (!q.empty()) { q.pop_front(); } 
            }
            else if (temp == ".") {}
            else { q.push_front(temp); }
        }
        
        // Queue Mode : Get Path by removing elements in order from queue.
        while (!q.empty()) {
            ans += q.back() + "/"; 
            q.pop_back(); 
        }
        
        // Post-processing to remove extra '/'
        while (ans.back() == '/') { 
            if (ans == "/") { break; }
            ans.pop_back(); 
        }
        
        return ans;
    }
};
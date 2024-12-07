#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/
// Difficulty : Medium

/*
    M = Number of Banned Numbers. (banned.size()) - [0,10^4]
    N = Range of Given Numbers. [1,n] - [0,10^9]
    ans = Maximum Number of Numbers whose Sum <= maxSum and do not contain any banned Numbers. - [1,~10^5]
*/

/* HASH TABLE + GREEDY METHOD - TC : O ( M + N ) */

// Using Hash Map
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        
        unordered_map<int,int> mp;
        int sum = 0, ans = 0;
        
        for (auto& i : banned) { mp[i] = 1; }

        for (int i=1;i<=n;i++) { 
            if (!mp[i]) {  
                sum += i; 
                if (sum > maxSum) { return ans; } ans++; 
            }                      
        }
        
        return ans;
    }
};

// Using Hash Set
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        
        unordered_set<int> ban;
        int sum = 0, ans = 0;
        
        ban.insert(banned.begin(),banned.end());

        for (int i=1;i<=n;i++) { 
            if (!ban.count(i)) {  
                sum += i; 
                if (sum > maxSum) { return ans; } ans++; 
            }                      
        }
        
        return ans;
    }
};

/* SORTING + BINARY SEARCH + GREEDY METHOD - TC : O ( ans*log(M) + M*log(M) ) */
class Solution {
public:
    bool search(vector<int>& a, int n, int key) {
        
        int low = 0, high = n, mid;

        while (low < high) {
            mid = (low + high)/2;
            if (a[mid] == key) { return true; }
            if (a[mid] > key) { high = mid; }
            else { low = mid + 1; }
        }
        
        return false;
    }   
    
    int maxCount(vector<int>& banned, int n, int maxSum) {
        
        
        sort(banned.begin(),banned.end());
        int sum = 0, ans = 0, m = banned.size();
        
        for (int i=1;i<=n;i++) { 
            if (!search(banned,m,i)) {  
                sum += i; 
                if (sum > maxSum) { return ans; } 
                ans++; 
            }                      
        }
        
        return ans;
    }
};
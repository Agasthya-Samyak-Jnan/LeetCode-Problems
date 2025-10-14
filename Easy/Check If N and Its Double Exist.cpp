#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/check-if-n-and-its-double-exist/
// Difficulty : Easy  

/* SORTING + BINARY SEARCH */
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        sort(arr.begin(),arr.end());

        int n = arr.size();

        for (int i=0;i<n;i++) {
            int low = (arr[i] >= 0) ? i+1 : 0, high = (arr[i] >= 0) ? n-1 : i-1, mid;
            while (low <= high) {
                mid = (low+high)/2;
                    if (arr[mid] == arr[i]*2) { return true; }
                    if (arr[mid] < arr[i]*2) { low = mid+1; }
                    else { high = mid-1; }
            }
        }

        return false;
    }
};

/* HASH SET ONLY */
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> hs;
        for (int num : arr) {
            if ((num % 2 == 0 and hs.find(num/2) != hs.end()) or hs.find(num*2) != hs.end()) { return true; }
            hs.insert(num);
        }
        return false; 
    }
};
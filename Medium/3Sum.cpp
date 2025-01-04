#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/3sum/
// Difficulty : Medium 

/* BASIC INTUITION + HASH TABLE - TIME LIMIT EXCEEDED for 10^4+ input size. */
class Solution {
public:

    unordered_set<string> triplets;

    // Duplicate Check Function
    bool isDuplicate (vector<int> t) {
        string triplet = vec_string(t);
        return (triplets.find(triplet) != triplets.end());
    }

    // Vector Serializer
    string vec_string (vector<int> t) {
        sort(t.begin(),t.end());
        string triplet = "";
        for (auto i : t) { triplet += to_string(i); }
        return triplet;
    }

    vector<vector<int>> threeSum(vector<int>& a) {
        
        int n = a.size();
        vector<vector<int>> ans;
        unordered_map<int,int> mp;

        for (int i=0;i<n-1;i++) {
            int target = 0 - a[i];
            for (int j=i+1;j<n;j++) {
                if (mp.find(a[j]) != mp.end()) { 
                    vector<int> triplet = {a[i],a[j],a[mp[a[j]]]};
                    if (!isDuplicate(triplet)) { 
                        triplets.insert(vec_string(triplet));
                        ans.push_back(triplet); 
                    } 
                }
                else { mp[target-a[j]] = j; }
            }
            mp.clear();
        }
        
        return ans;
    }
};

/* SORTING + TWO POINTERS */
class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& a) {
        
        int n = a.size();
        vector<vector<int>> ans;

        sort(a.begin(),a.end());

        for (int i=0;i<n-2;i++) {
            if (i>0 && a[i-1] == a[i]) { continue; }
            int left = i+1, right = n-1;
            while (left < right) {
                int sum = a[i] + a[left] + a[right];
                if (sum == 0) { 
                    ans.push_back({a[i],a[left],a[right]}); 
                    left++; right--;
                    while (left < right && a[left] == a[left-1]) { left++; }
                    while (left < right && a[right] == a[right+1]) { right--; }
                }
                else if (sum > 0) { right--; }
                else { left++; }
            }
        }
        
        return ans;
    }
};
#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/string-matching-in-an-array
// Difficulty : Easy

/* Custom Comparator for Sorting Strings by Length. */
bool compare (string& a, string& b) {
    return a.length() < b.length();
}

/* BASIC INTUITION */
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {

        int n = words.size();
        vector<string> ans;

        sort(words.begin(),words.end(),compare);

        for (int i=0;i<n-1;i++) {
            for (int j=i+1;j<n;j++) {
                if (words[j].find(words[i]) != string::npos) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }

        return ans;
    }
};
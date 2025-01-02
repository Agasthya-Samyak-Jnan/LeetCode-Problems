#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/count-vowel-strings-in-ranges/
// Difficulty : Medium 

/* BASIC INTUITION SOLUTION */
class Solution {
public:
    bool isVowel (char& c) {
        return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        int n = queries.size();
        vector<int> ans(n,0);

        for (int i=0;i<n;i++) {
            for (int j=queries[i][0];j<=queries[i][1];j++) {
                if (isVowel(words[j].front()) && isVowel(words[j].back())) {
                    ans[i]++;
                }
            }
        }

        return ans;
    }
};

/* PREFIX SUM SOLUTION : CREATE PREFIX SUM TABLE FOR VOWEL STRINGS AND GET QUERY BY DOING  ( PSUM[Lower Bound - 1] - PSUM[Upper Bound] ) */
class Solution {
public:
    bool isVowel (char& c) {
        return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        int m = words.size(), n = queries.size();
        vector<int> ans(n,0);
        vector<int> p_sum(m,0);

        p_sum[0] = isVowel(words[0].front()) && isVowel(words[0].back());
        for (int i=1;i<m;i++) { 
            p_sum[i] = p_sum[i-1] + (isVowel(words[i].front()) && isVowel(words[i].back())); 
        }

        for (int i=0;i<n;i++) {
            int low = (queries[i][0]<=0) ? 0 : p_sum[queries[i][0]-1], high = p_sum[queries[i][1]];
            ans[i] = high - low; 
        }

        return ans;
    }
};
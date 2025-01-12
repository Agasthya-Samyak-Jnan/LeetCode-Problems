#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/word-subsets
// Difficulty : Medium 

/* BASIC INTUITION - COMPARE CHARACTER FREQUENCY OF EACH LETTER OF EACH WORD IN WORDS2 WITH EACH WORD OF WORDS1,
   IF ITS NOT GREATER FOR EVEN A SINGLE WORD, ITS NOT UNIVERSAL 
*/
/* Time Complexity : M * N * K , Where K = Number of Unique Characters in Words of WORDS2 */
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        unordered_map<string,int> mp;
        int freq[26];
        unordered_map<string,unordered_map<char,int>> m2;
        vector<string> ans;

        for (string& word : words2) {
            if (mp[word]) { continue; }
            mp[word] = 1;
            for (char& letter : word) { m2[word][letter]++; }
        }

        for (string a : words1) {
            bool universal = true;
            for (char& letter : a) { freq[letter-'a']++; }
            for (auto& p1 : m2) {
                for (auto& p2 : m2[p1.first]) {
                    if (freq[p2.first-'a'] < p2.second) { universal = false; break; }
                }
                if (!universal) { break; }
            }
            if (universal) { ans.push_back(a); }
            memset(freq,0,sizeof(freq));
        }

        return ans;
    }
};

/* 
    OPTIMIZED SOLUTION : AGGREGATED MAXIMUM FREQUENCY MAP FOR WORDS2

    IDEA BY ChatGPT :
    The Problem
    You are given words1 and words2. To determine if a word from words1 is "universal," you need to ensure that it satisfies all the character requirements imposed by the words in words2.

    For example:
    words2 = ["e", "o"] means every universal word in words1 must:
    Contain at least one e (e: 1).
    Contain at least one o (o: 1).
    words2 = ["lo", "eo"] means every universal word in words1 must:
    Contain at least one l (l: 1).
    Contain at least one e (e: 1).
    Contain at least one o (o: 1).
    The requirement from words2 can be expressed as a single frequency map that aggregates the "maximum required count" of each character.
    
*/
/* With Hash Tables - (270-290ms)*/
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {

        unordered_map<char,int> freq;
        unordered_map<char,int> max_freq;
        vector<string> ans;

        for (string& word : words2) {
            for (char& letter : word) { 
                freq[letter]++; 
                max_freq[letter] = max(max_freq[letter],freq[letter]);
            }
            freq.clear();
        }

        for (string& a : words1) {
            for (char& letter : a) { freq[letter]++; }
            bool universal = true;
            for (auto& p : max_freq) {
                if (freq[p.first] < p.second) { universal = false; break; }
            }
            if (universal) { ans.push_back(a); }
            freq.clear();
        }

        return ans;
    }
};

/* Use Basic C-arrays to drastically decrease Overhead in maintaining Maps - (10-12ms)*/
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {

        int freq[26] = {0}, max_freq[26] = {0};
        vector<string> ans;

        for (string& word : words2) {
            for (char& letter : word) { 
                freq[letter-'a']++; 
                max_freq[letter-'a'] = max(max_freq[letter-'a'],freq[letter-'a']);
            }
            memset(freq,0,sizeof(freq));
        }

        for (string& a : words1) {
            for (char& letter : a) { freq[letter-'a']++; }
            bool universal = true;
            for (char i='a';i<='z';i++) {
                if (max_freq[i-'a'] == 0) { continue; }
                if (freq[i-'a'] < max_freq[i-'a']) { universal = false; break; }
            }
            if (universal) { ans.push_back(a); }
            memset(freq,0,sizeof(freq));
        }

        return ans;
    }
};

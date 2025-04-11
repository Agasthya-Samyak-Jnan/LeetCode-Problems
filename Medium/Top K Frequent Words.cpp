#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/top-k-frequent-words/
// Difficulty : Medium

/* HASH TABLE + MAX HEAP (PRIORITY QUEUE) */

// Custom Comparator : Keeps High Frequency Words on TOP, if frequnecies of Words are same, then keeps lexicographically smallest word on TOP.
struct compare {
    bool operator()(pair<int,string>& a, pair<int,string>& b) {
        if (a.first != b.first) { return a.first < b.first; }
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string,int> mp;
        // Intended Sorting Order obtained by passing above functor to this Priority Queue as template argument.
        priority_queue<pair<int,string>,vector<pair<int,string>>,compare> pq; 
        vector<string> topFrequentWords;

        // Get all Word Frequencies
        for (string word : words) { mp[word]++; }

        // Push those Words and thier Frequencies to Max Heap to Order By MAX frequency first, followed by lexical order if frequencies are equal.
        for (auto p : mp) { pq.push({p.second,p.first}); }

        // Get the First 'k' Words.
        while (k) {
            topFrequentWords.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        
        return topFrequentWords;
    }
};
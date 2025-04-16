#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/lexicographical-numbers/
// Difficulty : Medium 

/* LEXICOGRAPHICAL SORTING - O(N + NLogN) */
bool lexcompare (int& a, int& b) {
    return (to_string(a) < to_string(b));
}

class Solution {
public:
    vector<int> lexicalOrder(int n) {
       vector<int> ans(n);
       iota(ans.begin(),ans.end(),1);
       sort(ans.begin(),ans.end(),lexcompare);
       return ans;
    }
};

/* NUMBER TRIE + DEPTH-FIRST SEARCH - O(N + N) */
class Trie {
    public:

    Trie* a[10] = {0};
    
    Trie () {}
    
    void insert (int num) {
        Trie* t = this;
        string s = to_string(num);
        for (auto c : s) {
        t->a[c-'0'] = (!t->a[c-'0']) ? new Trie() : t->a[c-'0'] ;
            t = t->a[c-'0'];
        }
    }
    
};
    
class Solution {
public:
    
    void dfs (Trie* t, vector<int>& ans, int num) {
        if (!t) { return; }
        ans.push_back(num);
        for (int i=0;i<10;i++) { dfs(t->a[i],ans,num*10+i); }
    }
    
    vector<int> lexicalOrder (int n) {
        vector<int> ans;
        Trie* t = new Trie();
    
        for (int i=1;i<=n;i++) { t->insert(i); }
        dfs(t,ans,0);
    
        ans.erase(ans.begin());
    
        return ans;
    }
};

/* LEXCIALLY ORDERED DEPTH-FIRST SEARCH - O(N) */

class Solution {
public:
    
    void dfs (vector<int>& ans, int num, int n) {
        if (num > n) { return; }
        if (num == 0) { for (int i=1;i<10;i++) { dfs(ans,num*10+i,n); } }
        else { 
            ans.push_back(num);
            for (int i=0;i<10;i++) { dfs(ans,num*10+i,n); } 
        }
    }
    
    vector<int> lexicalOrder (int n) {
        vector<int> ans;
        dfs(ans,0,n);
        return ans;
    }
        
};
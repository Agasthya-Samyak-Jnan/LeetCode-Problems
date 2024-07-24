#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/map-sum-pairs/
// Difficulty : Medium


/* TRIE DATA STRUCTURE IMPLEMENTATION FOR UNDERSTANDING */
class MapSum {
public:
    MapSum* a[26];
    int is_Word;
    int value;
    
    MapSum() {
        memset(a,0,sizeof(a));
        is_Word = 0;
        value = 0;
    }
    
    void insert(string key, int val) {
         int n = key.length();
         MapSum* temp = this;
         for (int i=0;i<n;i++) {
             if (temp->a[key[i]-'a'] == 0) { temp->a[key[i]-'a'] = new MapSum(); }
             temp = temp->a[key[i]-'a'];
         }
         temp->is_Word = 1;
         temp->value = val;
    }
    
    int sum(string prefix) {
        
        MapSum* root = this;
        int n = prefix.length();
        int sum = 0;
        
        for (int i=0;i<n;i++) { 
            if(root->a[prefix[i]-'a'] != 0) { root = root->a[prefix[i]-'a']; }
            else { return sum; }
        }
        
        stack<MapSum*> s;
        s.push(root);
        while (!s.empty()) {
            MapSum* temp = s.top(); s.pop();
            for (auto i : temp->a) { if (i != 0) { s.push(i); } }
            if (temp->is_Word == 1) { sum += temp->value; }
        }
        
        return sum;
    }
};
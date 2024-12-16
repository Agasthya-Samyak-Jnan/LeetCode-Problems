#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/generate-parentheses/
// Difficulty : Medium 

/* BACKTRACKING SOLUTION : Build 'n' pairs combination of parentheses from 'n-1' pairs combination + a pair of parentheses. */

// Using Unordered Set to avoid repeated combinations.
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        unordered_set<string> ans = {"()"},temp;
        vector<string> ANS;
        
        for (int p=2;p<=n;p++) {
            for (auto& s : ans) {
                for (int i=0;i<s.size();i++) {
                    string t = s;
                    t.insert(i,"()");
                    temp.insert(t);
                }
            }
            ans = temp;
            temp.clear();
        }
        
        for (auto s : ans) { ANS.push_back(s); }
        
        return ANS;
    }
};

// Using Unordered Map to avoid repeated combinations.
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        unordered_map<string,int> mp;
        vector<string> ans = {"()"}, temp;
        
        for (int p=2;p<=n;p++) {
            for (auto& s : ans) {
                for (int i=0;i<s.size();i++) {
                    string t = s;
                    t.insert(i,"()");
                    if (!mp[t]) { temp.push_back(t); mp[t] = 1; }
                }
            }
            ans = temp;
            temp = {};
        }
        
        return ans;
    }
};

/* PYTHON3 VERSION - BACKTRACKING using DICTIONARY 

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        
        mp = {}
        ans = ["()"]
        temp = []
        
        for p in range(2,n+1) :
            for s in ans :
                for i in range(len(s)) :
                    c = s[:i+1] + "()" + s[i+1:]
                    if c not in mp:
                        mp[c] = True
                        temp.append(c)
                
            ans = temp
            temp = []
        
        
        return ans
                    
*/
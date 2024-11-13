#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/iterator-for-combination/
// Difficulty : Medium

/* DESIGN QUESTION */
class CombinationIterator {
public:
    vector<string> combinations;
    string temp;
    int i,n;
    
    CombinationIterator(string characters, int combinationLength) {
        solve(characters,0,combinationLength);
        i = 0;
        n = combinations.size();
    }
    
    // Find all Combinations of "Characters" of length "combinationLength"
    void solve (string& c, int i, int chars) {
        
        if (chars == 0) { 
            combinations.push_back(temp); 
            return; 
        }

        for (int j=i;j<c.size();j++) { 
            temp += c[j];
            solve(c,j+1,chars-1); 
            temp.pop_back();
        }
    }
    
    string next() {
        return combinations[i++];
    }
    
    bool hasNext() {
        return i < n;
    }
};
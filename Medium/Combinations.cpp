#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/combinations/
// Difficulty : Medium 

/* BACKTRACKING : COMBINATIONS - UNIQUE ARRANGEMENTS OR ALSO CALLED SELECTIONS */
class Solution {
public:
    int N; // Max Number of Items
    vector<int> temp; // To Keep Combination formed temporarily
    vector<vector<int>> ans; // Answer 
    
    void comb (int n, int k) {
        
        if (k == 0) { ans.push_back(temp); return; } // If all 'k' items are chosen, then put this (set of choices) into answer set.
           
        for (int i=n;i<=N;i++) { // Loop through all possible remaining Choices that you can explore or do.
            temp.push_back(i); // Choosing item 'i', and then finding other possible choices after choosing 'i'.
            comb(i+1,k-1);  // Explore all other possible choices after the above choice.
            temp.pop_back(); // After Finishing Exploration of all choices, backtrack to previous state to check for other possiblities from that point of choices.
        }                    // ANALOGY : Pausing a TV Show, going out and doing some work, come back to TV Show and RESUME it. Keep Repeating this.
    }                        // Here, Pop_back() means RESUMING TV Show , i.e Come back to previous state or instance.
    
    vector<vector<int>> combine(int n, int k) {
        N = n;
        comb(1,k);
        return ans; 
    }
};

int main () {
    Solution* a = new Solution();
    vector<vector<int>> ans = a->combine(4,3);
    for (auto i : ans) { for (auto j : i) { cout<<j<<","; } cout<<"  "; }
    return 0;
}

/* ITERATIVE FORM OF ABOVE BACKTRACKING SOLUTION */
class Solution {
public:
    
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> temp(k,0);
        vector<vector<int>> ans;
        
        int i = 0;
        
        while (i >= 0) {
            temp[i]++;
            if (temp[i] > n) { i--; }
            else if (i == k-1) { ans.push_back(temp); }
            else {
                i++;
                temp[i] = temp[i-1];
            }
        }
        
        return ans;
    }
};
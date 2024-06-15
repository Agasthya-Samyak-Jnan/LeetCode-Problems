#include<bits/stdc++.h>
#include<vector>
#include<algorithm>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/subsets-ii/
// Difficulty : Medium

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &a) {
          vector<vector<int>> ans;
          vector<int> subset;
          int currentSize = 0;
        
          ans.push_back(subset);
          sort(a.begin(),a.end());
          /* Sorting is Important for Two Reasons:
             1. It won't create Repetitive Subsets in middle, helping to find it right away.
             2. Detect Duplicate elements Quickly and not in middle. */
          for (int i=0;i<a.size();i++) {
              currentSize = ans.size();
              for (int j=0;j<currentSize;j++) {
                 subset = ans[j];
                 subset.push_back(a[i]); 
            /* Using "find()" check if the formed subset is previously obtained or not.  */
                 if(find(ans.begin(),ans.end(),subset)==ans.end()) {ans.push_back(subset);}
              }
          }
        return ans;
    }
};
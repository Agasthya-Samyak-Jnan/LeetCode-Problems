#include<bits/stdc++.h>
#include<vector>

// Link to the Problem : https://leetcode.com/problems/subsets/
// Difficulty : Medium

using namespace std;

/* Backtracking: Time Complexity (O(2^N * N)) Space Complexity(O(2^N * N))   */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& a) {
        
        /* Make Three Arrays/Vectors :
         * 1. To Store the Final Set of all possible Subsets seperately, make an Array of Arrays or Vector of Vectors. {{ , },{ , , },{}}
         * 2. To temporarily Store the subset found each time, create a normal array or vector. { , , }
         * 3. To Store Temporary set of subsets formed that includes a given element or number, make another Array of Arrays or Vector of Vectors. {{ , },{ , , },{}}.
        */

        vector<vector<int>> ans;
        vector<int> temp;
        vector<vector<int>> temp_subsets;
        
        ans.push_back(temp); // Push Empty Set to Answer Set because Empty Set is a Subset of All sets.
        
        // Loop through each element to find all subsets containing that element.
        for (int i=0;i<a.size();i++) {
            // Loop through and backtrack to all subsets previously formed to obtain all possible combinations, i.e subsets.
            // Backtracking doesn't end until all previous subsets have been combined with current element to get subsets with current element.
            for (auto it = ans.begin();it != ans.end();it++) {
                temp = *it; // Refresh with backtracked subset to get that subset with current element.
                temp.push_back(a[i]); // Add element to previously found subset to get new subset with current element.
                temp_subsets.push_back(temp); // Save it with set of subsets including current element.
            }
            ans.insert(ans.end()-1,temp_subsets.begin(), temp_subsets.end()); // Update answer set of subsets with Set of subsets including current element.
            temp_subsets.clear() ; // Empty the Set of Subsets to store subsets of next element.
        }
        // Return the Set of subsets
        return ans;
    }
};

// Driver Code
int main () {
   
    Solution* x = new Solution();
    vector<int> a = {1,2,3,4};
    vector<vector<int>> result = x->subsets(a);
    int  no_of_subsets =0;
    for (auto it : result) { 
        for (auto i : it) {
            cout << i << " "; 
        }
         no_of_subsets++;
        cout<<endl;
    }
    cout<<no_of_subsets<<endl;
    return 0;
}

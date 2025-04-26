#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/
// Difficulty : Medium

/* BELOW GRAPH - RECIPE - - -> INGREDIENT MAPPING */

/* DEPTH-FIRST SEARCH - PURE RECURSION 
    TRY DRAWING THE RELATIONSHIPS OF RECIPE WITH ITS INGREDIENTS GIVEN IN QUESTION, LOOKS LIKE A GRAPH ISN'T IT?
    TRY TO "MAKE" THE RECIPE - CHECK WHAT ALL INGREDIENTS YOU "NEED" TO MAKE IT - SIMILAR TO PREPARING FOOD IN KITCHEN.
    1. RECURSIVELY COLLECT AND PREPARE THE REQUIRED INGREDIENTS FROM YOUR SUPPLIES, 
    2. IF ALL INGREDIENTS ARE IN SUPPLIES OR YOU CAN BUILD SOME OR ALL INGREDIENTS NEEDED FOR THIS RECIPE FROM SUPPLIES - THIS RECIPE IS POSSIBLE.
    3. OTHERWISE IF YOU DON'T HAVE AT LEAST ONE INGREDIENT OR COULDN'T BUILD A INGREDIENT NEEDED FOR THIS RECIPE FROM SUPPLIES - THIS RECIPE IS IMPOSSIBLE!.
    4. AS PER THE QUESTION STATEMENT, RECIPES CAN CONTAIN EACH OTHER AS THIER INGREDIENTS => CYCLES IN RECIPE GRAPH. 
       NONE OF SUCH RECIPES CAN'T BE MADE AT ALL BECAUSE IN ORDER TO MAKE ONE OF THEM, THEY NEED ONE OF THEM AND VICE VERSA MAKING IT IMPOSSIBLE TO MAKE THEM.
*/
class Solution {
    public:
        unordered_map<string,int> visited;
    
        bool dfs (string recipe, unordered_map<string,vector<string>>& g, unordered_set<string>& sups) {
    
            if (g[recipe].empty()) { return (sups.find(recipe) != sups.end()); }
            if (sups.find(recipe) != sups.end()) { return true; }
            if (visited[recipe]) { return false; }
    
            visited[recipe] = 1;
    
            for (auto ingredient : g[recipe]) {
                if (!dfs(ingredient,g,sups)) { return false; }
                if (sups.find(ingredient) == sups.end()) { sups.insert(ingredient); }
            }
    
            return true; 
        }
    
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    
            unordered_map<string,vector<string>> g;
            vector<string> ans;
            int n = recipes.size();
    
            unordered_set<string> sups(supplies.begin(),supplies.end());
            for (int i=0;i<n;i++) { g[recipes[i]] = ingredients[i]; }
    
            for (auto recipe : recipes) {
                visited.clear();
                if (dfs(recipe,g,sups)) { ans.push_back(recipe); }
            }
            
            return ans;
        }
};

/* DEPTH-FIRST SEARCH + DYNAMIC PROGRAMMING - CACHE EACH CALL FOR CHECKING RECIPE POSSIBILITY - MEMOISATION + RECURSION */
class Solution {
    public:
        unordered_map<string,int> visited,dp;
    
        bool dfs (string recipe, unordered_map<string,vector<string>>& g, unordered_set<string>& sups) {
    
            if (dp.find(recipe) != dp.end()) { return dp[recipe]; }
            if (g[recipe].empty()) { return dp[recipe] = (sups.find(recipe) != sups.end()); }
            if (sups.find(recipe) != sups.end()) { return dp[recipe] = true; }
            if (visited[recipe]) { return dp[recipe] = false; }
    
            visited[recipe] = 1;
    
            for (auto ingredient : g[recipe]) {
                if (!dfs(ingredient,g,sups)) { return dp[recipe] = false; }
                if (sups.find(ingredient) == sups.end()) { sups.insert(ingredient); }
            }
    
            return dp[recipe] = true; 
        }
    
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    
            unordered_map<string,vector<string>> g;
            vector<string> ans;
            int n = recipes.size();
    
            unordered_set<string> sups(supplies.begin(),supplies.end());
            for (int i=0;i<n;i++) { g[recipes[i]] = ingredients[i]; }
    
            for (auto recipe : recipes) {
                visited.clear();
                if (dfs(recipe,g,sups)) { ans.push_back(recipe); }
            }
            
            return ans;
        }
};


/* BELOW GRAPH - INGREDIENT - - -> RECIPE MAPPING */

/* 
    KAHN'S ALGORITHM - BREADTH-FIRST SEARCH BASED TOPOLOGICAL SORTING - LEVEL BY LEVEL SOURCE REMOVAL 
    - At each instance, build all recipes you can with supplies you currently have.
    - If at any point of time, you cannot build any new recipes, then only recipes built till then are possible recipes.
*/
class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    
            unordered_map<string,vector<string>> g;
            unordered_map<string,int> incoming;
            vector<string> ans;
            int n = recipes.size();
    
            for (int i=0;i<n;i++) {
                incoming[recipes[i]] = ingredients[i].size();
                for (auto ingredient : ingredients[i]) {
                    g[ingredient].push_back(recipes[i]);
                }
            }
    
            queue<string> q;
    
            for (auto sup : supplies) { q.push(sup); }
    
            while (!q.empty()) {
                auto ingredient = q.front(); q.pop();
                for (auto recipe : g[ingredient]) { 
                    incoming[recipe]--; 
                    if (incoming[recipe] == 0) { 
                        ans.push_back(recipe); 
                        q.push(recipe);
                    }
                }
            }
            
            return ans;
        }
};
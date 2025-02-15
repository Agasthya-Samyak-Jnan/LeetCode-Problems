#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/
// Difficulty : Medium 

/* HASH TABLE SOLUTION */
class Solution {
    public:
        vector<int> queryResults(int limit, vector<vector<int>>& queries) {
    
            unordered_map<int,int> color, ballcolor;
            vector<int> result;
            int res = 0;
    
            for (auto& q : queries) {
                if (color[q[1]] == 0) { res++;  }
                color[q[1]]++;
                color[ballcolor[q[0]]]--;
                if (color[ballcolor[q[0]]] == 0) { res--; }
                ballcolor[q[0]] = q[1];
                result.push_back(res);
            }
            
            return result;
        }
};

/* PYTHON3 VERSION 
class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        
        color = defaultdict(int)
        ballcolor = defaultdict(int)
        result = []
        res = 0

        for q in queries :

            if color[q[1]] == 0 :
                res += 1

            color[q[1]] += 1
            color[ballcolor[q[0]]] -= 1

            if color[ballcolor[q[0]]] == 0 :
                res -= 1

            ballcolor[q[0]] = q[1]
            result.append(res)
        
        
        return result
*/
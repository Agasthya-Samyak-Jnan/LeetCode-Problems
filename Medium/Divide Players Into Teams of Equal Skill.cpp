#include<bits/stdc++.h>

using namespace std;

// Link to the Problem :
// Difficulty : 

/* SORTING METHOD - Time COmplexity : O(N*logN) */
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        
        int n = skill.size();
        sort(skill.begin(),skill.end());
        int team_skill = skill[0] + skill[n-1];
        long long chemistry = skill[0]*skill[n-1];
        
        for (int i=1;i<n/2;i++) {
            if (skill[i] + skill[n-1-i] != team_skill) { return -1; }
            chemistry += (skill[i]*skill[n-1-i]);
        }
        
        return chemistry;
    }
};

/* HASH TABLE METHOD - Time Complexity : O(N) */
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        
        int n = skill.size(), mini = INT_MAX, maxi = INT_MIN;
        long long chemistry = 0;
        
        int mp[1001];
        memset(mp,0,1001*sizeof(int));
        
        for (int i=0;i<n;i++) {
            mp[skill[i]]++;
            mini = min(mini,skill[i]);
            maxi = max(maxi,skill[i]);
        }
        
        int team_skill = mini + maxi;
        int i = mini;
        
        while (i<=maxi) {
            if (mp[i]) {
                mp[i]--;
                if (mp[team_skill-i] == 0) { return -1; }
                mp[team_skill-i]--;
                chemistry += i*(team_skill-i);
                if (mp[i] == 0) { i++; }
            }
            else { i++; }
        }
         
        return chemistry;
    }
};
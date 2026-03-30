#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/
// Difficulty : Medium

/* HASH TABLES - COMPARE FREQUENCIES OF CHRACTERS AT ODD AND EVEN INDICES OF BOTH STRINGS SEPERATELY, IDEA IS BASED ON PROBLEM DESCRIPTION. */
class Solution {
public:

    bool checkStrings(string s1, string s2) {
        
        int n = s1.length(); // or n = s2.length();
        vector<int> evenf1(26,0), evenf2(26,0), oddf1(26,0), oddf2(26,0);

        for (int i=0;i<n;i++) {
            // odd index
            if (i & 1) {
                oddf1[s1[i]-'a']++;
                oddf2[s2[i]-'a']++;
            }
            // even index
            else {
                evenf1[s1[i]-'a']++;
                evenf2[s2[i]-'a']++;
            }
        }

        return (evenf1 == evenf2) and (oddf1 == oddf2);
    }
};

/* SORTING - COLLECT ODD AND EVEN INDEX CHARACTERS OF BOTH STRINGS SEPERATELY, SORT EACH OF THEM SEPERATELY AND COMPARE THEM. */
class Solution {
public:

    bool checkStrings(string s1, string s2) {
        
        int n = s1.length(); // or n = s2.length();
        string odds1 = "", odds2 = "", evens1 = "", evens2 = "";

        for (int i=0;i<n;i++) {
            // odd index
            if (i & 1) {
                odds1 += s1[i];
                odds2 += s2[i];
            }
            // even index
            else {
                evens1 += s1[i];
                evens2 += s2[i];
            }
        }

        sort(odds1.begin(),odds1.end());
        sort(odds2.begin(),odds2.end());
        sort(evens1.begin(),evens1.end());
        sort(evens2.begin(),evens2.end());

        return (evens1 == evens2) and (odds1 == odds2);
    }
};
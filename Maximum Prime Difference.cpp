#include<bits/stdc++.h>
#include<vector>

// Link to the Problem : https://leetcode.com/problems/maximum-prime-difference/
// Difficulty : Medium

using namespace std;

/* Remember to Look Constraints, Constraints: 1 <= a[i] <= 100 */
/* Hash Table : Best Solution (74ms Runtime) */
class Solution {
public:
    int maximumPrimeDifference(vector<int> &a) {
     bool isPrime[101] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,
                        0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,
        0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0};
    
            for (int i=0;;i++) {
                if (isPrime[a[i]]) { 
                    for (int j=a.size()-1;;j--) {
                        if (isPrime[a[j]]) {
                            return j-i;
                        }
                    }
                } 
            }
     return -1;
    }
};

/* Condition Checking for Prime Under 100 - Simplified : (88ms Runtime) */
class Solution {
public:
    int maximumPrimeDifference(vector<int>& a) {
            int first=0, last=0; bool not_found_first = true;
            for (int i=0;i<a.size();i++) {
                if (a[i]%2 && a[i]%3 && a[i]%5 && a[i]%7 && a[i] != 1 || (a[i] == 2 || a[i] == 3 || a[i] == 5 || a[i] == 7)) { 
                    if (not_found_first) { first = i; not_found_first = false; }
                    last = i;
                }
            }
        if (!last) { return 0; }
        return last-first;
    }
};



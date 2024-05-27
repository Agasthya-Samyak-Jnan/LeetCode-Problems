#include<bits/stdc++.h>

using namespace std;

// Link to the Problem: https://leetcode.com/problems/single-number/
// Difficulty: Easy

/* Problems Restricts your Time Complexity to O(n) and Space Complexity to O(1).
   Hence, i have found the fact about XOR operator.
   The XOR Operator outputs 0 when a Same Number is Operated using it for EVEN number of times and Number ITSELF when Odd Number of Times.
   Hence, XOR of all Numbers in array is taken , since they have given target number appears only once, and all others twice.
*/

/* Time Complexity: O(n) */
class Solution {
public:
    int singleNumber(vector<int>& a) {
        int ans=0;
        for(auto i:a) { ans ^= i; }
        return ans;
    }
};
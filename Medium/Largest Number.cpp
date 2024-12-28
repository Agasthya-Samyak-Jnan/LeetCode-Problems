#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/largest-number
// Difficulty : Medium

// DO LEXICOGRAPHICAL ORDERING BASED TWO POSSIBLE CONCATENATED STRINGS THEY CAN FORM.
// THEN ORDER THEM ON MAX-HEAP SUCH THAT WHEN REMOVED ONE-BY-ONE THEY FORM LARGEST NUMBER.
// THE ORDERING SHOULD BE SUCH THAT EVEN PARTIAL INPUT WHEN IN HEAP , SHOULD BE ORDERED SUCH THAT THEY THEMSELVES FORM LARGEST NUMBER.
struct custom_comparator {
    bool operator()(string& a, string& b) {
        return a+b < b+a; 
    }
};

class Solution {
public:
    string largestNumber (vector<int>& nums) {

        priority_queue<string,vector<string>,custom_comparator> pq;
        string ans = "";
        bool all_zero = true;

        for (int num : nums) { 
            if (num != 0) { all_zero = false; }
            pq.push(to_string(num)); 
        }

        if (all_zero) { return "0"; }

        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};
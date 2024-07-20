#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/add-binary/
// Difficulty : Easy

class Solution {
public:
    string addBinary(string a, string b) {
        
        if (a == "0") { return b; }
        if (b == "0") { return a; }
        
        int i = a.length()-1, j = b.length()-1, k = max(i+1,j+1);
        int carry = 0;
        string ans(max(i+1,j+1)+1,'0');
        string t;
        
        while (i>=0 && j>=0) {
            int temp = (int)(a[i]-'0') + (int)(b[j]-'0') + carry;
            carry = temp/2;
            ans[k] = '0' + temp%2;
            k--; i--; j--;
        }
        
        if (i>=0) { t = a; }
        else { i = j; t = b; }
        
        while (i>=0) {
            int temp = (int)(t[i]-'0') + carry;
            carry = temp/2;
            ans[k] = '0' + temp%2;
            k--; i--;
        }
        
        if (carry) { ans[k] = '1'; }
        
        ans = ans.substr(ans.find_first_not_of('0'));
        
        return ans;    
    }
};
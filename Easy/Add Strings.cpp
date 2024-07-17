#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/add-strings/
// Difficulty : Easy

class Solution {
public:
    string addStrings(string num1, string num2) {
        
        // If we add "0" to "something" , its "something" itself.
        if (num1 == "0") { return num2; }
        if (num2 == "0") { return num1; }
        
        string a,b;
        
        if (num1.length()>=num2.length()) { a = num1; b = num2; }
        else { a = num2; b = num1; }
        
        int m = a.length(), n = b.length();
        
        // Addition could result in a bigger number with 1 extra digit maximum.
        string ans(m+1,'0');
        
        int carry = 0, temp = 0, i = m-1, k = m, j = n-1;
        
        while (j>=0) {
            temp = (int)(a[i]-'0') + (int)(b[j]-'0') + carry;
            ans[k] = '0' + temp%10;
            carry  = temp/10; 
            k--; i--; j--;
        }
        
        while (i>=0) {
            temp = (int)(a[i]-'0') + carry;
            ans[k] = '0' + temp%10;
            carry = temp/10;
            i--; k--;
        } 
        
        // If carry is left after all addition add it at end. example : 100 + 900
        if (carry) { ans[k] = '1'; }
        
        // Trim the Leading Zeroes.
        size_t startpos = ans.find_first_not_of('0');
        if (startpos<m+1) { ans = ans.substr(startpos); }
        
        return ans; 
    }
};

    int main () {
        Solution* x = new Solution();
        string a,b;
        cin>>a>>b;
        cout<<x->addStrings(a,b);

        return 0;
    }
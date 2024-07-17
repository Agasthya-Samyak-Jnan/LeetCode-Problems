#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/multiply-strings/
// Difficulty : Medium 

/* Elementary School Multiplication Method - DO NOT CONVERT NUMBER STRINGS TO INTEGERS !!! 
   The testcases have numbers up till 10^200 !!! , i have tried this method already and got mad !
   Its normal to think initially that "Elementary School Method" is lengthy and there might be better solution.
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        
        if (num1 == "0" || num2 == "0") { return "0"; }
        
        int m = num1.length(), n = num2.length(), j = n-1, i = n-1;
        string ans(m+n,'0');
        int k = m+n-1;
        int places_done = 0;
        int carry = 0 , temp = 0;

        while (i>=0) {
            j = m-1;
            carry = temp = 0;
            k = m+n-1-places_done;
            while (j>=0) {
                temp = (int)(ans[k]-'0') + (int)(num1[j]-'0')*(int)(num2[i]-'0') + carry;
                carry = temp / 10;
                ans[k] = '0' + temp%10;
                j--;
                k--;
            }
            if (carry > 0) { ans[k] = '0' + carry; }
            places_done++;
            i--;
        }  
        ans = ans.substr(ans.find_first_not_of('0'));
        return ans;
    }
};

int main () {
    string a,b;
    cin>>a>>b;
    Solution* x = new Solution();
    cout<<x->multiply(a,b);
    return 0;
}

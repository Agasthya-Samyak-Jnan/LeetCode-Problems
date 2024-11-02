#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/complex-number-multiplication/
// Difficulty : Medium


class Solution {
public:
    pair<int,int> parseComplex (string num) {
        
        int r,i = 0,n = num.length();
        string real, imag;
        
        int j = 0; // To iterate over string
        // Parse Real Part, which is from start till "+".
        while (num[j] != '+') { real += num[j]; j++; }
        j++; // Skip Over "+"
        // Parse Imaginary Part, which is after "+" till "i".
        while (num[j] != 'i') { imag += num[j]; j++; }
        
        // Convert Parts to Integers
        r = stoi(real);
        i = stoi(imag);
        
        return {r,i};
        
    }
    
    string complexNumberMultiply(string num1, string num2) {
        
        pair<int,int> n1 = parseComplex(num1);
        pair<int,int> n2 = parseComplex(num2);
        string ans;
        
        // cout<<n1.first<<"+"<<n1.second<<"i\n";
        // cout<<n2.first<<"+"<<n2.second<<"i\n";
        
        // i*i == -1 and (a+bi)(c+di) = ac + adi + bic + bidi = ac + (ad+bc)i - bd
        int ra = n1.first*n2.first -(n1.second*n2.second);
        int ia = n1.first*n2.second + n1.second*n2.first;
        
        ans = to_string(ra) + "+" + to_string(ia) + "i";
        
        return ans;
        
    }
};
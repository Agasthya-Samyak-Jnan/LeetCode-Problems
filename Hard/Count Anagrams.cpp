#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/count-anagrams/
// Difficulty : Hard

/* 
    COUNTING MATHEMATICS : 
    * FORMULA TO FIND DISTINCT PERMUTATIONS WHEN ITEMS ARE ALLOWED TO REPEAT. 
    * HOW TO CALCULATE MOD OF LARGE NUMBER DIVISIONS - MODULAR MULTIPLICATIVE INVERSE.
*/
class Solution {
public:
    const int mod = 1e9 + 7;

    // Find Modular Multiplicative Inverse of 'b' in mod of 'a'.
    int multi_inverse (int a, int b) {
        int q,r,t1=0,t2=1,t;
        while (b) {
            q = a/b; r = a%b; a = b; b = r;
            t = t1 - q*t2; t1 = t2; t2 = t;
        }
        return t1<0 ? t1+mod : t1;
    }

    // Factorial Calculator.
    unsigned long long fact (int n) {
        unsigned long long ans = 1;
        for (unsigned long long i = 2; i <= n; ++i) { ans = (ans*i) % mod; }
        return ans;
    }
    
    int countAnagrams(string s) {
        
        int freq[26] = {0}, n = s.length(), mx = INT_MIN, mn = INT_MAX;
        unsigned long long ans = 1;
        
        for (int i=0;i<n;i++) {
            
            int j=0;
            unsigned long long temp=0;
            
            // Count Characters in Word.
            while (i<n && s[i] != ' ') { 
                freq[s[i]-'a']++; 
                mx = max(mx,s[i]-'a');
                mn = min(mn,s[i]-'a');
                j++; 
                i++; 
            }
            
            // Find Total Permutations of Word.
            temp = fact(j);
            
            // Find Distinct Permutations of Word.
            for (int j=mn;j<=mx;j++) {
                if (freq[j]>1) { temp = (temp*multi_inverse(mod,fact(freq[j]))) % mod; }
            }
            
            ans = (ans*temp) % mod;
            memset(freq,0,sizeof(freq));
        }
        
        return ans;
    }
};
#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/count-and-say/
// Difficulty : Medium 

/* RECURSIVE SOLUTION */
class Solution {
public:
    string countAndSay(int n) {
        
        if (n == 1) { return "1"; }
        
        string temp = countAndSay(n-1), ans ="";
        
        int k = 1, m = temp.length();
        for (int i=1;i<=m;i++) {
            if (temp[i-1] == temp[i]) { k++; }
            else { 
                ans += to_string(k) + temp[i-1];
                k = 1;
            }
        }
        
        return ans;
    }
};

/* ITERATIVE SOLUTION */
class Solution {
public:
    string countAndSay(int n) {
        
        if (n == 1) { return "1"; }
        
        string temp = "1";
        
        for (int i=1;i<n;i++) {
            
            int k = 1, m = temp.length();
            string ans = "";
            
            for (int j=1;j<=m;j++) {
                if (temp[j-1] == temp[j]) { k++; }
                else { 
                    ans += to_string(k) + temp[j-1];
                    k = 1;
                }
            }
            
            temp = ans;
        }
        
        return temp;
    }
};

/* PYTHON SOLUTION */

// RECURSIVE SOLUTION 
// class Solution:
//     def countAndSay(self, n: int) -> str:
        
//         if n == 1 :
//             return "1"
        
//         ans = ""
//         temp = self.countAndSay(n-1)
//         m = len(temp)
//         k = 1
        
//         for i in range(1,m+1):
//             if i<m and temp[i-1] == temp[i] :
//                 k += 1
//             else :
//                 ans += f"{k}{temp[i-1]}"
//                 k = 1
        
//         return ans

// ITERATIVE SOLUTION 
// class Solution:
//     def countAndSay(self, n: int) -> str:
        
//         if n == 1:
//             return "1"
        
//         temp = "1"
        
//         for i in range(1,n):
            
//             k = 1
//             m = len(temp)
//             ans = ""
            
//             for j in range(1,m+1):
//                 if j<m and temp[j-1] == temp[j]:
//                     k += 1
//                 else :
//                     ans += f"{k}{temp[j-1]}"
//                     k = 1
                
//             temp = ans
            
//         return temp
                
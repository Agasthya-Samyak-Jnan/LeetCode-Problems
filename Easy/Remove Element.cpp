#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/remove-element/
// Difficulty : Easy

class Solution {
public:
    int removeElement(vector<int>& a, int target) {
        int n = a.size();
        int i=0,j=n-1;
        
        while (i<=j) {
            if (a[j]==target) { j--; continue; }
            if (a[i]==target) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                j--;
            }
            i++;
        }
        return i;
   }  
};
#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/longest-turbulent-subarray/
// Difficulty : Medium

/* SLIDING WINDOW 
   Find largest window containing alternating comparison signs. If it doesn't alternate anymore in this window, start new window from where it stopped.
   A failpoint where comparison signs don't alternate involves 3 numbers at most, choose the middle number because a window could start from there.
*/

/* INITIAL BAD SOLUTION */
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        
        int i = 0, j = 1, n = arr.size(), max_len = 2;

        if (n == 1) { return 1; }

        while (j<n and arr[i] == arr[j]) { i++; j++; }

        if (j>=n) { return 1; }
 
        bool d = (arr[i] > arr[j]);
        j++;

        while (j<n) {
            if (d) {
                if (arr[j-1] < arr[j]) { 
                    d = !d; 
                    max_len = max(max_len,j-i+1);
                    j++;
                }
                else { 
                    if (arr[j-1] == arr[j]) { i = j; j++; }
                    else { i = j-1; }
                    d = (arr[i] > arr[j]);
                    j++;
                }
            }
            else {
                if (arr[j-1] > arr[j]) {
                    d = !d;
                    max_len = max(max_len,j-i+1);
                    j++;
                }
                else {
                    if (arr[j-1] == arr[j]) { i = j; j++; }
                    else { i = j-1; }
                    d = (arr[i] > arr[j]);
                    j++;
                }
            }
        }

        return max_len;
    }
};

/* REDUCED SOLUTION */
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        
        int i = 0, j = 1, n = arr.size(), max_len = 2;

        while (j<n and arr[i] == arr[j]) { i++; j++; }
        if (j>=n) { return 1; }
 
        bool d = (arr[i] > arr[j]);
        j++;

        while (j<n) {
            if ((d and arr[j-1] < arr[j]) or (!d and arr[j-1] > arr[j])) { 
                d = !d; 
                max_len = max(max_len,j-i+1);
            }
            else { 
                if (arr[j-1] == arr[j]) { i = j; j++; }
                else { i = j-1; }
                d = (arr[i] > arr[j]);
            }
            j++;
        }

        return max_len;
    }
};
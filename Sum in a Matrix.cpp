#include<bits/stdc++.h>
#include<vector>
#include<stack>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/sum-in-a-matrix/
// Difficulty : Medium

/*
"ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);"
  is often used to optimize input and output performance.

ios_base::sync_with_stdio(false);:
This disables the synchronization between the C and C++ standard streams. 
By default, the C++ streams (cin, cout, etc.) are synchronized with their C counterparts (stdin, stdout, etc.). 
This synchronization allows you to use both C and C++ style I/O together, but it also incurs a performance cost. 
Disabling it allows for faster I/O operations but means you shouldn't mix C-style and C++-style I/O.

cin.tie(NULL);:
By default, cin is tied to cout. 
This means that cin will flush cout before reading input. 
Flushing ensures all output operations are completed before the input operation starts, but it can slow down the program. 
Setting the tie to NULL unties cin from cout, which can improve performance when you don't need this automatic flushing.

cout.tie(NULL);:
Similarly, this unties cout from any tied stream. 
By default, cout is not tied to any other stream, so this line is generally redundant. 
However, it's included to ensure no ties exist that might cause unnecessary flushing.

DOES SIGNIFICANT PERFORMANCE BOOST IN TERMS OF RUNTIME !!!
*/

class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        
        int mx=0, m=nums.size(), n=nums[0].size(), sum=0;
        
        // Sorting All Arrays to get Right Answer.
        for(int i=0;i<m;i++) {
            sort(nums[i].begin(),nums[i].end());
        }
         
        // Find Highest Number in Columns and Sum Up.
        for (int i=0;i<n;i++) {
            mx = 0;
            for (int j=0;j<m;j++)  {
                mx = max(mx,nums[j][i]);
            }
            sum += mx;
        }
        
        return sum;
    }
};
#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence
// Difficulty : Medium

class Solution {
    public:
        vector<int> ans,nums;
        int size,n;
    
        bool solve (int i) {
    
            if (i >= size) { return true; }
    
            if (ans[i] != 0) { return solve(i+1); }
    
            for (int j=n;j>=1;j--) {
                if (nums[j]) {
                    if (j > 1 && (i+j >= size || ans[i+j] != 0)) { continue; }
                        
                    ans[i] = j;
                    if (j > 1) { ans[i+j] = j; }
                    nums[j] = 0;
    
                    if (solve(i+1)) { return true; }
    
                    ans[i] = 0;
                    if (j > 1) { ans[i+j] = 0; }
                    nums[j] = 1;
                }
            }
            
            return false;
        }
    
        vector<int> constructDistancedSequence(int n) {
    
            size = 1+2*(n-1);
            this->n = n;
            ans = vector<int>(size,0);
            nums = vector<int>(n+1,1);
    
            solve(0);
    
            return ans;
        }
};

/* JAVA SOLUTION 

    class Solution {
    public

        int[] ans;
        boolean[] used;
        int size,n;

        boolean solve (int i) {

            if (i >= size) { return true; }

            if (ans[i] != 0) { return solve(i+1); }

            for (int j=n;j>=1;j--) {
                if (!used[j]) {
                    if (j > 1 && (i+j >= size || ans[i+j] != 0)) { continue; }
                        
                    ans[i] = j;
                    if (j > 1) { ans[i+j] = j; }
                    used[j] = true;

                    if (solve(i+1)) { return true; }

                    ans[i] = 0;
                    if (j > 1) { ans[i+j] = 0; }
                    used[j] = false;
                }
            }
            
            return false;
        }

        int[] constructDistancedSequence(int n) {

            size = 1+2*(n-1);
            this.n = n;
            ans = new int[size];
            used = new boolean[n+1];

            solve(0);

            return ans;
        }
    }

*/

/* PYTHON3 SOLUTION 

    class Solution:
    
    def __init__ (self) :
        self.ans = []
        self.nums = []
        size = 0
        n = 0


    def solve (self,i) :

        if i >= self.size : 
            return True 

        if self.ans[i] != 0 :
            return self.solve(i+1)

        for j in range(self.n,0,-1) :

            if self.nums[j] : 
                if j > 1 and (i+j >= self.size or self.ans[i+j] != 0) : 
                    continue
                    
                self.ans[i] = j
                if j > 1 :
                     self.ans[i+j] = j
                self.nums[j] = 0;

                if self.solve(i+1) :
                    return True

                self.ans[i] = 0;
                if (j > 1) :
                    self.ans[i+j] = 0; 
                self.nums[j] = 1
        
        return False

    def constructDistancedSequence(self, n: int) -> List[int]:

        self.size = 1+2*(n-1)
        self.n = n;
        self.ans = self.size*[0]
        self.nums = (self.n+1)*[1]

        self.solve(0)

        return self.ans
*/
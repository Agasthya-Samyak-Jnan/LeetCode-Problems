#include<bits/stdc++.h>

// Link to the Problem: https://leetcode.com/problems/permutations/
// Difficulty: Medium

using namespace std; 

void permutations(vector<vector<int> >& ans,vector<int> nums,int i) { 

    if (i == nums.size()-1) { 
        ans.push_back(nums); 
        return; 
    } 

    for (int j = i; j <= nums.size()-1; j++) { 

        int temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;

        permutations(ans, nums, i+1); 

        temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
    } 
} 

vector<vector<int>> permute (vector<int> &num) {
    vector<vector<int>> ans;
    permutations(ans,num,0);
    return ans;
}

/* 
PYTHON3 VERSION 

class Solution:
    def __init__ (self) :
        self.ans = []
        self.temp = []
        self.selected = 0
        self.nums = []
        self.n = 0
    
    def solve (self) :
        if self.selected != pow(2,self.n)-1 :
            for i in range(0,self.n) :
                if (self.selected>>i)&1 == 1 :
                    continue
                self.temp.append(self.nums[i])
                self.selected = self.selected^(1<<i)
                self.solve()
                self.selected = self.selected&(~(1<<i))
                self.temp.pop()
        else :
            self.ans.append(copy.deepcopy(self.temp))
    
    def permute(self, nums: List[int]) -> List[List[int]]:
        
        self.nums = nums
        self.n = len(nums)
        
        self.solve()
        
        return self.ans
*/

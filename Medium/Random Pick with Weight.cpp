#include <bits/stdc++.h>

// Link to the Problem: https://leetcode.com/problems/random-pick-with-weight/
// Difficulty: Medium

/* RANDOMIZED + PREFIX SUM + BINARY SEARCH */
/*
    - FIRST IDEA is to generate random float number and compare it with w[i]/sum(w) for every random index 'i' generated.
      if random float number <= w[i]/sum(w) for that 'i' index, then pick that index or keep repeating these steps.
      This simulates weighted sampling because if w[i]/sum(w) is large, chances of random float number generated coming under it would be large.
      But since generate randomly, if it doesn't come under that value repeatedly, we will take a lot of time in picking a index. 

    - So, what we can do is we take w[i] as a range of values for that index 'i', so w[i] numbers quantify index 'i's importance.
    - The more numbers, the more importance as the range of numbers will be larger and increased chances of getting a number within it.
    - So, for each index 'i', numbers from w[i-1] to w[i] represent index 'i', we will randomly sample a number 'num' from 0 to sum(w) (maximum possible weight value)
    - Then using binary search we will find lowest index whose weight is less than current randomly sampled number, return that index.
    - This takes O(log(n)) time per pickIndex query and O(n) time for building weight ranges for each index.
*/
using namespace std; 

class Solution {
public:
    int n, sum;
    vector<int> w; 

    Solution(vector<int>& w) {
        n = w.size();
        sum = w[0];
        for (int i=1;i<n;i++) { 
            sum += w[i];
            w[i] += w[i-1]; 
        }
        this->w = w;
        srand(time(0));
    }

    int pickIndex() {
        int weight = rand() % sum;
        int low = 0, high = n-1, mid;

        while (low < high) {
            mid = (low+high)/2;
            if (w[mid] <= weight) { low = mid+1; }
            else { high = mid; }
        }

        return low;
    }
};

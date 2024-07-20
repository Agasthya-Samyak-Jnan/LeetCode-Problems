#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/array-partition/
// Difficulty : Easy 

/* YOU CAN DO THIS WAY - I DIDN'T THNIK THIS FIRST THO */
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum=0,n = nums.size();
        for(int i=0;i<n;i+=2){
            sum+=nums[i];
        }
        return sum;
    }
};

/* Fully Elaborated Solution - Counting Sort + GREEDY FOR SMALLEST NUMBER - My Dumb Brain went for this .... */
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        
        int arr[20001];
        memset(arr,0,sizeof(arr));
        int n = nums.size();
        int sum = 0, maximum = 0, minimum = 0;
        
        for (int i=0;i<n;i++) { 
            arr[nums[i]+10000] += 1; 
            maximum = max(maximum,nums[i]);
            minimum = min(minimum,nums[i]);
        }
        
        nums.clear();
        minimum += 10000;
        maximum += 10000;
        
        for (int i=minimum;i<=maximum;i++) { 
            while (arr[i]) {
                nums.push_back(i-10000); 
                if (nums.size()%2 == 1) { sum += nums[nums.size()-1]; } // Greedy Here, always choosing odd index number because
                arr[i]--;                                               // After Sorting , even indexed numbers will be minimum among pairs starting from 0-index.
            }
        }
        
        return sum;
    }
};
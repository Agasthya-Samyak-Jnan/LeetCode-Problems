#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

//Link to the Problem: https://leetcode.com/problems/3sum-closest/submissions/
//Difficulty: Medium

int threeSumClosest(int* nums, int numsSize, int target) {
    int i,j,k,diff=INT_MAX, sum = 0;
    
    for (i=0;i<numsSize-2;i++) {
        for (j=i+1;j<numsSize-1;j++) {
            for (k=j+1;k<numsSize;k++) {
                
                if (abs(target-(nums[i]+nums[j]+nums[k])) < diff) 
                { 
                    printf("%d sum , %d diff\n", sum, diff);
                    sum = nums[i]+nums[j]+nums[k];
                    diff = abs(target - sum);
                }
            }
        }
    }
    return sum;
}

int main () {
    int a[3] = {-1000,-1000,-1000};
    printf("%d\n", threeSumClosest(a,3,10000));
    return 0;
}
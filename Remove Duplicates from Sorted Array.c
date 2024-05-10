#include<stdio.h>
#include<stdlib.h>

//Link to the Problem: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
//Difficulty: Easy

int removeDuplicates(int* nums, int numsSize) {
    
     
    int i=1, j=1;
    
    while (i < numsSize) {
    
        if (nums[i] != nums[i-1]) {
           nums[j] = nums[i];
            j++;
        }
        i++;
    }
    return j;
}

int main () {

int a[4] = {1,1,2,3};
printf("%d\n", removeDuplicates(a,4));
for (int i=0;i<4;i++) { printf("%d ", a[i]); }
return 0;

}
#include<bits/stdc++.h>

using namespace std; 

// Link to the Problem : https://leetcode.com/problems/sort-an-array/
// Difficulty : Medium

/* Best Time Complexity Solution : O(N) - COUNTING SORT ALGORITHM */
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        
        int max_limit = 50000;
        
        vector<int> a(2*max_limit+1,0);
        int maxx = 0, n = nums.size();
        
        // Memorize Values = Count Values in a Table , count repetitions (purpose of '++'), Keep track of MAX value to check upto.
        for (int i=0;i<n;i++) { 
            a[nums[i]+max_limit]++; 
            maxx = max(nums[i],maxx);
        }
        
        nums.clear();
        
        // Go in Ascending Order and Write repeated elements if present (purpose of 'while' loop)
        for (int i=0;i<=maxx+max_limit;i++) {
            while (a[i]) { nums.push_back(i-max_limit); a[i]--; }
        }
        
        return nums;
    }
};

/* Best Space Complexity : O(logN) (Recursion Stack) - HEAP SORT ALGORITHM - IN PLACE VERSION */

class Solution {
public:
    // This has been done JUST TO MAKE CODE LOOK SIMPLER.
void swap (int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Convert Heap to Max Heap 
void max_heapify (vector<int>& arr, int i, int n) {
     int largest = i;  // Assume Current PARENT is LARGEST.          Note: In Array, 2i+1 = LEFT, 2i+2 = RIGHT.
     if ((2*i+1)<n && arr[largest]<arr[2*i+1]) { largest = 2*i+1; }  // Check if LEFT child > Current PARENT , if so LEFT Child is now the LARGEST.
     if ((2*i+2)<n && arr[largest]<arr[2*i+2]) { largest = 2*i+2; }  // Check if RIGHT child > Current LARGEST , if so RIGHT Child is LARGEST of 3.
     if (largest != i) {  // If PARENT node was NOT LARGEST, ONLY then SWAP to make it LARGEST.
        swap(arr[largest],arr[i]); // Swap the LARGEST value to PARENT node. (Max Heap Rule : Parent Always Greater than Children. ( Applies to Real Life as well, but not in exceptional cases. ))
        max_heapify(arr,largest,n); // Convert Modified Heap to Max Heap to maintain MAX value at ROOT.
     }
}

// Heap Sorting Algorithm
void heap_sort (vector<int>& arr,int n) {
    
    /* First We Have to Construct Heap Such That LARGEST value is at the ROOT. Construct = Rearrange in this case of Array Representation.
       Checking from (n/2-1) would be enough because of Two Reasons:
       1. 0-indexed Array, hence '-1' from 'n/2' should be start point.
       2. A Heap is always a Complete Tree and there will be no more than 1 Height difference in any case, 'n/2' always will be
          one level before the last leaf node in any heap, hence 'n/2'.
    */
    for (int i=n/2-1;i>=0;i--) { max_heapify(arr,i,n); }
    
    /* After building heap as needed, Start Sorting: 
       *. Heap was Constructed such that initially the MAX element is at root. Hence, 1st Step is to Remove MAX element at root.
       1. Remove MAX element at ROOT (arr[0] in Array) by SWAPPING it with LAST LEAF NODE (arr[i]) that is present at present state (i) of heap.
       2. Max Heapify the Modified Heap.
       3. Invalidate the Sorted Node or Number by decrementing 'i'.
       4. Repeat until all Elements are Removed or Invalidated from Heap.
    */
    for (int i=n-1;i>0;i--) {
        swap(arr[0],arr[i]);
        max_heapify(arr,0,i);
    }
}
    vector<int> sortArray(vector<int>& nums) {
        heap_sort(nums,nums.size());
        return nums;
    }
};
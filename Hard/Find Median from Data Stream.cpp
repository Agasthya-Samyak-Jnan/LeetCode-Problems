#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-median-from-data-stream/
// Difficulty : Hard

/* SPLIT DATA STREAM INTO STARTING HALF AND ENDING HALF AND STORE THEM SUCH THAT WHEN BOTH HALVES ARE JOINED THEY ARE IN SORTED ORDER. */
/*  
    MEDIAN = MIDDLE NUMBER IN A SORTED SET OF NUMBERS. HENCE, WE NEED EFFICIENT ACCESS TO MIDDLE OF THE DATA STREAM.
    USE MAX-HEAP TO STORE START TO MIDDLE OF STREAM WITH MIDDLE AT TOP - MIDDLE NUMBER IS LARGEST IN STARTING HALF. (SH)
    USE MIN-HEAP TO STORE MIDDLE TO END OF STREAM WITH MIDDLE AT TOP - MIDDLE NUMBER IS SMALLEST IN ENDING HALF. (EH)

    YOU CAN PRIORITISE ADDING ELEMENTS TO EITHER (SH) OR (EH). I PRIORITISED ADDING ELEMENTS TO STARTING HALF FIRST.
    MEDIAN = TOP ELEMENT OF (SH) + TOP ELEMENT OF (EH) WHEN STARTING HALF AND ENDING HALF HAVE SAME NUMBER OF ELEMENTS.
*/

class MedianFinder {
    public:
        priority_queue<int> SH; // Starting Half (SH) stored in MAX HEAP.
        priority_queue<int,vector<int>,greater<int>> EH; // Ending Half (EH) stored in MIN HEAP.
        int SHL = 0, EHL = 0; // SHL = Starting Half Length, EHL = Ending Half Length
    
        MedianFinder() {}
        
        // O(logN) Time for Adding.
        void addNum(int num) {
            if (SHL == EHL) { SH.push(num); SHL++; }
            else { EH.push(num); EHL++; }
    
            if (!SH.empty() and !EH.empty() and SH.top() > EH.top()) {
                int a = SH.top(), b = EH.top();
                SH.pop(); EH.pop();
                SH.push(b);
                EH.push(a);
            }
        }
        
        // O(1) Time for calculating Median.
        double findMedian() {
            if (SHL == EHL) { return (double)(SH.top()+EH.top())/2; }
            else { return SH.top(); }
        }
};
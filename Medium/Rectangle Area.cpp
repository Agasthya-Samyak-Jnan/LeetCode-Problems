#include<bits/stdc++.h>

using namespace std;

// Link to the Problem: https://leetcode.com/problems/rectangle-area/
// Difficulty: Medium

/* Simple and First Intuition Solution (3ms Runtime) */
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {

        // Calculate Area of Two Rectangles
        int a1 = abs(ax2-ax1)*abs(ay2-ay1);
        int a2 = abs(bx2-bx1)*abs(by2-by1);
        
        // Perfect Overlap: 2 Cases
        // Complete Overlap: First Rectangle inside Second Rectangle
        if (ax1 >= bx1 && ay1 >= by1 && ax2 <= bx2 && ay2 <= by2) { return a2; }
        // Complete Overlap: Second Rectangle inside First Rectangle
        if (ax1 <= bx1 && ay1 <= by1 && ax2 >= bx2 && ay2 >= by2) { return a1; }
        
        // No Overlap
        if ((bx1 >= ax2 || bx2 <= ax1) || (by1 >= ay2 || by2 <= ay1)) { return a1+a2; }
        
        /* Partial Overlap: 
        Find X-Bounds and Y-Bounds of Rectangle formed by Overlapping of Two Rectangles 
        Remove Area of that Rectangle from Sum of Areas of Two Rectangles */
        int mx1 = max(ax1,bx1); 
        int my1 = max(ay1,by1);
        int mx2 = min(ax2,bx2);
        int my2 = min(ay2,by2);
        int a3 = abs(mx2-mx1)*abs(my2-my1);
        return (a1+a2)-a3;
    }
};

/* Best Solution  (0ms Runtime) */
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        const auto iw = std::min(ax2, bx2) - std::max(ax1, bx1);
        const auto ih = std::min(ay2, by2) - std::max(ay1, by1);
        const int combined_area = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);

        return combined_area - (iw > 0 && ih > 0 ? iw * ih : 0);
    }
};
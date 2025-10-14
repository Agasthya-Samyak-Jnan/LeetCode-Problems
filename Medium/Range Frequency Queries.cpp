#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/range-frequency-queries/
// Difficulty : Medium 

/* SEGMENT TREE - Whenever it is related to Range Queries and you need to optimize for BOTH Time and Space - O(log(L-R)) Time, O(2*N) Space */

/* Static Segment Tree API - Iterative , 2N Space , Optimized */
class SegmentTree {
    public:
        // t = Array that logically represents Segment Tree, arr = Original Array
        vector<unordered_map<uint16_t,uint32_t>> t;
        int n;
    
        SegmentTree (vector<int>& arr) {    
            n = arr.size();
            t = vector<unordered_map<uint16_t,uint32_t>>(2*n);
            build(arr);
        }
    
        // Build Segment Tree from Given Array - O(N) Time, O(2N) Space - Divide and Conquer but Bottom-Up.
        void build (vector<int>& a) {
            for (int i=0;i<n;i++) { t[n+i][a[i]] = 1; }
            for (int i=n-1;i>0;i--) {
                for (auto&p : t[2*i]) { t[i][p.first] += p.second; }
                for (auto&p : t[2*i+1]) { t[i][p.first] += p.second; }
            }

        }

        int freq (int left, int right, int val) {
            left += n;
            right += n;
            int freq = 0;
            while (left <= right) {
                if (left % 2 == 1) {
                    freq += t[left][val];
                    left++;
                }
                if (right % 2 == 0) {
                    freq += t[right][val];
                    right--;
                }
                left /= 2;
                right /= 2;
            }
            return freq;
        }
};

class RangeFreqQuery {
public:
    SegmentTree* s;

    RangeFreqQuery(vector<int>& arr) {
        s = new SegmentTree(arr);
    }
    
    int query(int left, int right, int value) {
        return s->freq(left,right,value);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
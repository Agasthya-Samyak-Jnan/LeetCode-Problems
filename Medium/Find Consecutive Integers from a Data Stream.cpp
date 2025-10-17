#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/
// Difficulty : Medium 

/* COUNTING - START COUNTING WHENEVER 'VALUE' STARTS COMING UP (QUEUE SOLUTION IS FIRST INTUITION, BUT SEEMS DUMB AFTER YOU THINK FOR A WHILE)*/
class DataStream {
public:
    int val, K, count;

    DataStream(int value, int k) {
        val = value;
        K = k;
        count = 0;
    }
    
    bool consec(int num) {
        if (num == val) { count++; }
        else { count = 0; }
        return (count >= K);
    }
};

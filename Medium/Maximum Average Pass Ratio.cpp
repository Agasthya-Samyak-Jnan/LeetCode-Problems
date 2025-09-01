#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/maximum-average-pass-ratio/
// Difficulty : Medium 

/* GREEDY TYPE INTUITION */

/* USE PRIORITY QUEUE TO ADD STUDENTS TO THAT CLASS AT EACH ITERATION, THAT WILL HAVE HIGHEST INCREASE IN ITS PASS RATIO DUE TO ADDING OF 1 STUDENT TO IT. */

/* UNOPTIMIZED, HIGHLY READBALE SOLUTION (1500+ ms Runtime, 350+MB Space on LeetCode TestCases) */
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
        double n = classes.size(), ratio_sum = 0.0, pass, total, increase;
        priority_queue<vector<double>> pq;

        for (auto c : classes) { 
            pass = c[0];
            total = c[1];
            ratio_sum += (pass/total);
            increase = ((pass+1)/(total+1))-(pass/total);
            pq.push({increase,pass,total}); 
        }

        while (extraStudents) {
            vector<double> c = pq.top(); pq.pop();
            increase = c[0];
            pass = c[1]+1;
            total = c[2]+1;
            ratio_sum += increase;
            increase = ((pass+1)/(total+1))-(pass/total);
            pq.push({increase,pass,total}); 
            extraStudents--;
        }

        return ratio_sum/n;
    }
};

/* OPTIMIZED, LEAST READBALE SOLUTION (300-340 ms Runtime, 100-110 MB Space on LeetCode TestCases) */
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
        struct COMPARE {
            bool operator()(const pair<double,double>& a, const pair<double,double>& b) {
                return (((a.first+1)/(a.second+1))-(a.first/a.second)) < (((b.first+1)/(b.second+1))-(b.first/b.second));
            }
        };

        double n = classes.size(), ratio_sum = 0.0, pass, total, increase;
        priority_queue<pair<double,double>,vector<pair<double,double>>,COMPARE> pq;

        for (auto c : classes) { 
            ratio_sum += ((double)c[0]/(double)c[1]);
            pq.push({c[0],c[1]}); 
        }

        while (extraStudents) {
            auto [pass,total] = pq.top(); pq.pop();
            ratio_sum += (((pass+1)/(total+1))-(pass/total));
            pq.push({pass+1,total+1}); 
            extraStudents--;
        }

        return ratio_sum/n;
    }
};
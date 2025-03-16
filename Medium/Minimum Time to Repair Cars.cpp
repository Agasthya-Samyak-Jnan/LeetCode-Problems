#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/minimum-time-to-repair-cars/
// Difficulty : Medium

/* PRIORITY-QUEUE - MIN HEAP FOR SELECTING MECHANIC TAKING NEXT TOTAL LEAST TIME WHILE DISTRIBUTING CARS. */
class Solution {
    public:
        long long repairCars(vector<int>& ranks, int cars) {
    
            long long rank_freq[101] = {0}, time, srm, cr, rank;
            priority_queue<vector<long long>,vector<vector<long long>>, greater<vector<long long>>> pq;
    
            for (auto& r : ranks) { rank_freq[r]++; }

            /*
                Each Heap Entry Contains :
                v[0] = time = total time taken after repairing this 'cr'th car.
                v[1] = srm = number of same-ranked mechanics.
                v[2] = cr = cars repaired by each mechanic of this rank.
                v[3] = rank = rank of the mechanic.

            */
            for (long long rank=0;rank<101;rank++) {
                if (rank_freq[rank]) { pq.push({rank,rank_freq[rank],0,rank}); }
            }

            // srm = same ranked mechs, cr = cars repaired by this mechanic.
            while (cars > 0) {
                auto v = pq.top(); pq.pop();
                time = v[0], srm = v[1], cr = v[2], rank = v[3];
                cr++;
                cars -= srm; // Each same ranked mech can repair 1 car at the same time.
                pq.push({rank*(cr+1)*(cr+1),srm,cr,rank});
            }
    
            return time;
        }
};
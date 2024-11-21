#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/gas-station/
// Difficulty : Medium 

/* SIMULATION - SIMULATE THE JOURNEY FROM STATION TO STATION */
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        
        for (int i=0;i<n;i++) {
            if (cost[i] > gas[i]) { continue; }
            int gas_tank = gas[i], j,k = 0;
            for (j=i;cost[j%n]<=gas_tank;j++) {
                gas_tank = gas_tank - cost[j%n] + gas[(j+1)%n]; 
                k++;
                if (k == n) { return i; }
            }
            i = j; // IF YOU START FROM 'i' station move till 'j' station and fail at 'j'th station , 
                   // then all those stations are invalid starting points , since if you start at any of them ,
                   // you have to come across the failure station - 'j'th station, skip all these stations. - GREEDY OPTIMISATION.
        }
        
        return -1; 
    }
};
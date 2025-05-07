#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/design-underground-system/
// Difficulty : Medium 

/* HASH TABLES AND HASH MAPS : HOW TO USE BOTH OF THEM THE WAY YOU NEED. */
class UndergroundSystem {
    public:
        unordered_map<string,unordered_map<string,pair<int,int>>> time; // Map {start,end} Stations -> {total travelled time, Number of Passenger Travel Sessions} between these stations.
        unordered_map<int,pair<string,int>> checkedin; // Map {passenger id} -> {time when they checked in} : Useful to compute time taken by passenger to go from start to end station.
    
        UndergroundSystem () {}
        
        // Keep in memory when 'id' passenger has came to "stationName" station.
        void checkIn(int id, string stationName, int t) {
            checkedin[id] = {stationName,t};
        }
        
        void checkOut(int id, string stationName, int t) {
            string start = checkedin[id].first; // Know from which station this passenger 'id' has came from.
            int timeTaken = t - checkedin[id].second; // Calculate total travel time : (when they came to start station) - (when they reached end station)
            time[start][stationName].first += timeTaken; // Add this passenger's travel time to total travel time between these stations. Necessary for calculating average.
            time[start][stationName].second++; // This adds One Travel Session between these Stations.
        }
        
        // Average Time = Average of all Travel Times from every Travel Session between these Stations
        // Average Time = (Sum of all Travel Session Times) / (Number of Travel Sessions)
        double getAverageTime(string startStation, string endStation) {
            return (double)time[startStation][endStation].first/(double)time[startStation][endStation].second;
        }
};
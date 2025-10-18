#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/design-a-food-rating-system/
// Difficulty : Medium 

/* HASH TABLES + HASH MAPS + ORDERED MAPS + ORDERED SETS : HOW TO DESIGN SYSTEMS */
class FoodRatings {
public:
    unordered_map<string,map<int,set<string>>> mp;
    unordered_map<string,pair<string,int>> f2cr;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i=0;i<n;i++) { 
            mp[cuisines[i]][ratings[i]].insert(foods[i]); 
            f2cr[foods[i]] = {cuisines[i],ratings[i]}; 
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = f2cr[food].first;
        int oldRating = f2cr[food].second;
        mp[cuisine][oldRating].erase(food);
        if (mp[cuisine][oldRating].empty()) { mp[cuisine].erase(oldRating); }
        f2cr[food].second = newRating;
        mp[cuisine][newRating].insert(food);
    }
    
    string highestRated(string cuisine) {
        return *((*(mp[cuisine].rbegin())).second.begin());
    }
};
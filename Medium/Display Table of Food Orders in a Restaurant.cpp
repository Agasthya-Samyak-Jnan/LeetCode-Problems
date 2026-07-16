#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/
// Difficulty : Medium
 
/* HASH TABLES + ORDERED SETS (HOW TO USE SORTED CONTAINERS to solve problems) */
class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {

        auto comparator = [](const string& a, const string& b){ return stoi(a) < stoi(b); };

        set<string> foods;
        set<string, decltype(comparator)> tables;
        unordered_map<string,unordered_map<string,int>> t2f;
        unordered_map<string,int> f2i;
        vector<vector<string>> disp;

        for (auto o : orders) {
            tables.insert(o[1]);
            foods.insert(o[2]);
            t2f[o[1]][o[2]]++;
        }

        int rows = tables.size() + 1, cols = foods.size() + 1;
        for (int i=0;i<rows;i++) { disp.push_back({}); }

        disp[0].push_back("Table");
        for (auto food : foods) { 
            disp[0].push_back(food);
            f2i[food] = disp[0].size()-1; 
        }

        auto it = tables.begin();
        for (int i=1;i<rows;i++) {
            disp[i].push_back(*it);
            for (int j=0;j<cols-1;j++) { disp[i].push_back("0"); }
            for (auto fc : t2f[*it]) {
                    string food = fc.first;
                    int cnt = fc.second;
                    disp[i][f2i[food]] = to_string(cnt);
            }
            it++;
        }
 
        return disp;
    }
};
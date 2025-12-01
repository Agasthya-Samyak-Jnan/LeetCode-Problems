#include <bits/stdc++.h>

// Link to the Problem: https://leetcode.com/problems/design-spreadsheet/
// Difficulty: Medium

using namespace std;

/* HOW TO USE HASH TABLE LIKE IT'S A DAILY THING */
class Spreadsheet {
public:

    unordered_map<int,unordered_map<char,int>> sheet;

    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        sheet[stoi(cell.substr(1,cell.length()-1))][cell[0]] = value;
    }
    
    void resetCell(string cell) {
        sheet[stoi(cell.substr(1,cell.length()-1))][cell[0]] = 0;
    }
    
    int getValue(string formula) {
        
        int i = 1, value = 0;
        vector<string> cells;
        string temp = "";
        
        while (formula[i]) {
            if (formula[i] == '+') { cells.push_back(temp); temp = ""; }
            else { temp += formula[i]; }
            i++;
        }
        cells.push_back(temp);

        for (auto cell : cells) {
            if (!isalpha(cell[0])) { value += stoi(cell); }
            else { value += sheet[stoi(cell.substr(1,cell.length()-1))][cell[0]]; }
        }

        return value;
    }
};
#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/simple-bank-system/
// Difficulty : Medium

/* HASH TABLE + SIMULATION */
class Bank {
    public:
        vector<long long> ACC;
        int n;
    
        Bank(vector<long long>& balance) {
            n = balance.size();
            ACC.push_back(-1);
            for (long long i : balance) { ACC.push_back(i); }
        }
    
        // Check if Account lies in the range [1,n]
        bool isValid (int account) {
            return (account > 0 and account <= n);
        }
        
        bool transfer(int account1, int account2, long long money) {
            if (isValid(account1) and isValid(account2) and ACC[account1] >= money) {
                ACC[account1] -= money;
                ACC[account2] += money;
                return true;
            }
            return false;
        }
        
        bool deposit(int account, long long money) {
            if (isValid(account)) {
                ACC[account] += money;
                return true;
            }
            return false;
        }
        
        bool withdraw(int account, long long money) {
            if (isValid(account) and ACC[account] >= money) {
                ACC[account] -= money;
                return true;
            }
            return false;
        }
};
    

#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-the-count-of-good-integers/
// Difficulty : Hard

/* PERMUTATIONS AND COMBINATIONS - COUNTING THEORY IN MATHEMATICS */
class Solution {
    public:
        // To reverse a number - useful for making palindromes
        int _reverse (int num) {
            int rnum = 0;
            while (num) {
                rnum = rnum*10 + num%10;
                num /= 10;
            }
            return rnum;
        }
        
        // To find n!
        long long _fact (int n) {
            if (n <= 1) { return 1; }
            long long ans = 1;
            for (int i=2;i<=n;i++) { ans *= i; }
            return ans; 
        }
        

        long long countGoodIntegers(int n, int k) {
            
            // All single digits are palindromic. Divisbility Checks are enough.
            if (n == 1) {
                int goodInts = 0;
                for (int i=1;i<10;i++) { if (i%k == 0) { goodInts++; } }
                return goodInts;
            }
    
            int low = pow(10,(n-1-(n%2 == 1))/2), high = (low*10) - 1;
            long long goodInts = 0;
            string num;
            unordered_map<int,int> mp;
            unordered_map<string,int> repeated_perm;
    
            for (int num=low;num<=high;num++) {

                // If Number has Even Number of Digits
                if (n%2 == 0) {
                    
                    // Build the Palindromic Number - Half Num | reverse of Half Num
                    long long palindrome = num*pow(10,n/2) + _reverse(num);
    
                    if (palindrome % k == 0) {
                        // You may come across permutations that were already considered before, check if that occured.
                        string num = to_string(palindrome); // Convert to string because rearranging number itself to certain order to identify all permutations is hard.
                        sort(num.begin(),num.end()); // By Sorting, you can identify all permutations using a single permutation that is sorted lexically.
                        if (repeated_perm[num]) { continue; } // Check if we had counted the set of permutations represented by this permutation, if yes DON'T COUNT AGAIN.
                        repeated_perm[num] = 1; // Mark it - as we are counting this set  now.
    
                        long long permutations = _fact(n); // Total Permutations possible in a N-digit Number is N!

                        // Get the Repetitions for each digit in Number.
                        while (palindrome) {
                            mp[(palindrome%10)]++;
                            palindrome /= 10;
                        }
                        
                        /*  Counting Theory Rule : if there are repeated elements when counting permutations, 
                                divide total permutation by frequency of repetition of each repeated element.
                        */
                        for (auto p : mp) { permutations /= (_fact(p.second)); }
                        
                        /* REMOVE those permutations that CONTAIN LEADING ZEROES. */
                        if (mp[0]) {
                            mp[0]--;
                            long long invalid = _fact(n - 1);
                            for (auto& p : mp) { invalid /= _fact(p.second); }
                            mp[0]++;
                            permutations -= invalid;
                        }
                        
                        /* CLEAR old data from frequency table to use it for next Number */
                        mp.clear();
                        goodInts += permutations; // All the counted Permutations are "Good" Integers - Palindromic and Divisible by 'k'.
    
                    }
                }

                // If Number has Odd Number of Digits
                else {
                    for (int i=0;i<10;i++) {
                        
                        // Build the Palindromic Number - Half Num | mid num | reverse of Half Num
                        long long palindrome = num*pow(10,n/2+1) + i*pow(10,n/2) + _reverse(num);
    
                        if (palindrome % k == 0) {
                            
                            // You may come across permutations that were already considered before, check if that occured.
                            string num = to_string(palindrome); // Convert to string because rearranging number itself to certain order to identify all permutations is hard.
                            sort(num.begin(),num.end()); // By Sorting, you can identify all permutations using a single permutation that is sorted lexically.
                            if (repeated_perm[num]) { continue; } // Check if we had counted the set of permutations represented by this permutation, if yes DON'T COUNT AGAIN.
                            repeated_perm[num] = 1; // Mark it - as we are counting this set  now.
    
                            long long permutations = _fact(n); // Total Permutations possible in a N-digit Number is N!
                            
                            // Get the Repetitions for each digit in Number.
                            while (palindrome) {
                                mp[(palindrome%10)]++;
                                palindrome /= 10;
                            }
                            
                            /*  Counting Theory Rule : if there are repeated elements when counting permutations, 
                                divide total permutation by frequency of repetition of each repeated element.
                            */
                            for (auto p : mp) { permutations /= (_fact(p.second)); }
                            
                            /* REMOVE those permutations that CONTAIN LEADING ZEROES. */
                            if (mp[0]) {
                                mp[0]--;
                                long long invalid = _fact(n - 1);
                                for (auto& p : mp) { invalid /= _fact(p.second); }
                                mp[0]++;
                                permutations -= invalid;
                            }
                            
                            /* CLEAR old data from frequency table to use it for next Number */
                            mp.clear();
                            goodInts += permutations; // All the counted Permutations are "Good" Integers - Palindromic and Divisible by 'k'.
    
                        }
    
                    }
                }
    
            }
            
            return goodInts;
        }
};
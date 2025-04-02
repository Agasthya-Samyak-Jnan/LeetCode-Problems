#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/frequency-tracker/
// Difficulty : Medium

/* HASH MAPS - BIDIRECTIONAL MAPPING - NUMBERS TO THIER FREQUENCY COUNTS AND FREQUENCY COUNTS TO COUNT OF NUMBERS HAVING IT. */
class FrequencyTracker {
    public:
        // n_f = Number to its Frequency Mapping, f_n = Frequency that is same to 'n' Numbers Mapping.
        unordered_map<int,int> n_f, f_n;
    
        FrequencyTracker() {}
        
        void add(int number) { 
            f_n[n_f[number]]--; // Since frequency of this number changes, decrease count of numbers having this old frequency by 1.
            n_f[number]++; // Update the Frequency of this Number.
            f_n[n_f[number]]++; //  Since this is the new frequency of this number, increase count of numbers having this new frequency by 1.
        }
        
        void deleteOne(int number) {
            if (n_f[number]) { // IF THIS NUMBER HAS OCCURED AT LEAST ONCE BEFORE,
                f_n[n_f[number]]--; // Since frequency of this number changes, decrease count of numbers having this old frequency by 1.
                n_f[number]--; // Update the Frequency of this Number.
                f_n[n_f[number]]++; //  Since this is the new frequency of this number, increase count of numbers having this new frequency by 1.
            }
        }
        
        bool hasFrequency(int frequency) {
             return (f_n[frequency] > 0); // If at least one number has this frequency, then return true.
        }
};
    
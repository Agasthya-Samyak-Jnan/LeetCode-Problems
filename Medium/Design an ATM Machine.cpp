#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/design-an-atm-machine/
// Difficulty : Medium 

/* ARRAY + GREEDY 
    GREEDY : AS PER THE QUESTION DESCRIPTION, ALWAYS TRY AS MANY HIGHER DENOMINATION NOTES AS POSSIBLE - GREEDY FOR BIG NOTES.
    ARRAY : STORE COUNT OF NOTES OF EACH DENOMINATION
*/

class ATM {
public:

    vector<int> denominations,notes;
    int d;

    // Initialise with given Denominations. (below implementation is Generalised to any set of denominations)
    ATM() {
        denominations = {20,50,100,200,500};
        d = denominations.size();
        notes = vector<int>(d,0);
    }
    
    // Simply put notes into ATM
    void deposit(vector<int> banknotesCount) {
        for (int i=0;i<d;i++) { notes[i] += banknotesCount[i]; }
    }
    
    // Check if the transaction is possible; then withdraw by subtracting notes from ATM that are given out to user, otherwise don't remove notes from ATM.
    vector<int> withdraw(int amount) {
        
        vector<int> notesGiven(d,0);
        int i;

        for (i=d-1;i>=0;i--) {
            int n = amount/denominations[i];
            if (notes[i] < n) { 
                amount -= denominations[i]*notes[i]; 
                notesGiven[i] = notes[i];
            }
            else {
                amount = amount%denominations[i];
                notesGiven[i] = n;
            }
        }

        if (amount == 0) { 
            for (i=0;i<d;i++) { notes[i] -= notesGiven[i]; }
            return notesGiven; 
        }

        return {-1};
    }
};
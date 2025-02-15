#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-the-punishment-number-of-an-integer/
// Difficulty : Medium

/* BACKTRACKING SOLUTION */
class Solution {
    public:
    
        bool split_check (int sq, int i) {
    
            if (i == sq) { return true; }
    
            if (i < 0) { return false; }
    
            for (int d=1000;d>=10;d/=10) {
                if (sq/d != 0 and (split_check(sq/d,i-sq%d) or split_check(sq%d,i-sq/d))) {
                    return true;
                }
            }
    
            return false;
        }
    
        int punishmentNumber(int n) {
    
            int sum = 0;
            
            for (int i=1;i<=n;i++) { sum += split_check(i*i,i) ? i*i : 0; }
    
            return sum;
        }
};

/* JAVA SOLUTION

    class Solution {

    public boolean split_check (int sq, int i) {

        if (i == sq) { return true; }

        if (i < 0) { return false; }

        for (int d=1000;d>=10;d/=10) {
            if (sq/d != 0 && (split_check(sq/d,i-sq%d) || split_check(sq%d,i-sq/d))) {
                return true;
            }
        }

        return false;
    }

    public int punishmentNumber(int n) {

        int sum = 0;
        
        for (int i=1;i<=n;i++) { sum += split_check(i*i,i) ? i*i : 0; }

        return sum;

    }
}

*/

/* PYTHON3 SOLUTION 

    class Solution:

    def split_check (self,sq,i) :

        if i == sq :
            return True

        if i < 0 :
            return False 

        d = 1000
        while d >= 10 :
            if sq//d > 0 and (self.split_check(sq//d,i-sq%d) or self.split_check(sq%d,i-sq//d)) :
                return True
            d /= 10
        
        return False
        

    def punishmentNumber(self, n: int) -> int:

        sum = 0

        for i in range(1,n+1) :
            if self.split_check(i*i,i) :
                sum += i*i

        return sum

*/
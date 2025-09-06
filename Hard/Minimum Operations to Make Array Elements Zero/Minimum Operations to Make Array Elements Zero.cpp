#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/
// Difficulty : Hard

/* 
    THOUGHT PROCESS :

    - We want to convert a number to zero by doing floor(x/4) and One operation is defined as doing that on two numbers at once.

    - I just divided some sample numbers by  4 and immediately undestood that it takes "floor(log4(x)) + 1" Steps to do so for any number 'x'.
      floor() is needed to truncate floating point numbers into integers.

    - Each number needs "floor(log4(x)) + 1" Steps to be reduced to zero, but since each operation involves two numbers simultaneously,
      number of operations would be less than 'N*(floor(log(x))+1)', where 'N' is total number of numbers in a given interval of numbers.

    - After manually calculating (dry running) the count of operations needed to make zero for a handful of intervals , 
      I noticed the pattern that, Minimum number of operations needed to make all numbers in a given range to zero by this operation is,
      SUM of "floor(log(x))+1" of all numbers in given range [a,b] divided by 2.

    - Then comes below solution of doing the above thing quite literally but it was a lot unoptimised than i thought and got TLE.

*/

/* TIME LIMIT EXCEEDED - O(N^2) SOLUTION - INTUITION AND NUMBER PROPERTIES */
class Solution {
public:

    long long minOperations(vector<vector<int>>& queries) {
        
        long long operations = 0;
        
        for (auto q : queries) {
            long long ops = 0;
            for (int i=q[0];i<=q[1];i++) {
                ops += log(i)/log(4) + 1;
            }
            operations += (ops+(ops&1))/2;
        }

        return operations;
    }
};

/*
    - After observing the solution and reconsidering the goal of problem, i understood two things :
        - The only part that has some scope for optimisation, is the part where you SUM up the operations per number. 
          You might try finding a general equation for it based on some mathematical equations or laws.
        - You can't process all given intervals at once because as per definition of problem itself, input intervals in this 
        
    - So I thought a lot about how we try to optimise the SUM part which took O(N) time (or 'N' iterations) for an interval of size 'N',
      to much lesser time complexity or even thought on how to find a direct single computation that finds the sum. (lol)

    - Then, after recalling some of my mathematics knowledge, summation of functions can be done using INTEGRALS from CALCULUS (hahahaha, welcome back calculus).

    - My target function was F(X) = floor(log4(x)) + 1 , and i need to find its INTEGRAL to get its SUM over [a,b]. (this will get real complicated soon).
      But, the floor() function is a step function changing in intervals of [4^k,4^(k+1)) depending on 'k'. So, this isn't normal integral 
      that will output a variable-based single equation that directly gives you sum. This is Iterative Integral !

    - The rest of thought process on how i derived the equation is in PDF i attached with this file. Look it ! 
    
*/

/* O(N*log4(b-a)) SOLUTION - INTEGRAL OF OPERATIONS COUNTING FUNCTION - F(X) = I [floor(log4(x)) + 1] */
class Solution {
public:

    long long integral (int a, int b) {
        
        long long k = 0, sum = 0;

        // Find the 'k' for Starting Intervals of Powers of 4 - [4^k,4^(k+1)) 
        while (a > pow(4,k)) { k++; }  

        // If [a,b] lies inside [4^k,4^(k+1)) completely
        if (b < pow(4,k)) {
            return (k) * (b - a + 1);
        }

        // Initial Partial Interval
        sum += (k) * (pow(4,k) - a);
        
        // Full Intervals of [4^k,4^(k+1)) in between Initial and Ending Partial Intervals
        while (pow(4,k) <= b && pow(4,k+1) <= b) { 
            sum += (k+1) * (pow(4,k+1) - pow(4,k)); 
            k++; 
        }

        // Ending Partial Interval
        sum += (k+1) * (b - pow(4,k) + 1); 

        return sum;
    }

    long long minOperations(vector<vector<int>>& queries) {
        
        long long operations = 0;
        
        for (auto q : queries) {
            operations += (integral(q[0],q[1]) + 1) / 2;
        }

        return operations;
    }
};

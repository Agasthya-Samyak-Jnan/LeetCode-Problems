#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/print-zero-even-odd/
// Difficulty : Medium 

/* CONCURRENCY : MULTITHREADING AND SYNCHRONIZATION BETWEEN THREADS USING BINARY SEMAPHORES */

/* 
   Execution of Each Thread Should Repeat until you print 'n' number. Hence the Infinite While Loop. 
   When i == n, printing is completed. Then, you should take measure to not starve other threads before terminating current thread.
   Hence, you have to post semaphores that this thread would do before terminating to avoid making other threads waiting indefinitely 
   on this semaphore.
*/

class ZeroEvenOdd {
private:
    int n,i;
    sem_t Even, Odd, Zero;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        sem_init(&Zero,0,1);
        sem_init(&Even,0,0);
        sem_init(&Odd,0,0);
        i = 1;
    }
    
    ~ZeroEvenOdd () {
        sem_destroy(&Zero);
        sem_destroy(&Even);
        sem_destroy(&Odd);
    }

    // printNumber(x) outputs "x", where x is an integer.
    
    void zero(function<void(int)> printNumber) {
         while (1) {   
            sem_wait(&Zero);
            if (i > n) { sem_post(&Even); sem_post(&Odd); return; }
            printNumber(0);
            if (i%2 == 1) { sem_post(&Odd); }
            else { sem_post(&Even); }
         }
    }

    void even(function<void(int)> printNumber) {
        while (1) {
             sem_wait(&Even);
            if (i > n) { sem_post(&Zero); return; }
            printNumber(i++);
            sem_post(&Zero);
        }
    }

    void odd(function<void(int)> printNumber) {
        while (1) {   
            sem_wait(&Odd);
            if (i > n) { sem_post(&Zero); return; }
            printNumber(i++);
            sem_post(&Zero);
        }
    }
};
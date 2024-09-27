#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/fizz-buzz-multithreaded/
// Difficulty : Medium


/* CONCURRENCY : SYNCHRONIZATION USING MUTUAL EXCLUSION OF PROCESSES (MUTEX LOCKS) */
class FizzBuzz {
private:
    int n;
    int i;
    pthread_mutex_t lock;

public:
    FizzBuzz(int n) {
        this->n = n;
        i = 1;
        pthread_mutex_init(&lock,NULL);
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (1) {
            pthread_mutex_lock(&lock);
            if (i>n) { pthread_mutex_unlock(&lock); return; }
            if (i%3 == 0 && i%5 != 0) {
                printFizz();
                i++;
            }
            pthread_mutex_unlock(&lock);
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (1) {
            pthread_mutex_lock(&lock);
            if (i>n) { pthread_mutex_unlock(&lock); return; }
            if (i%5 == 0 && i%3 != 0) {
                printBuzz();
                i++;
            }
            pthread_mutex_unlock(&lock); 
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while (1) {
            pthread_mutex_lock(&lock);
            if (i>n) { pthread_mutex_unlock(&lock); return; }
            if (i%3 == 0 && i%5 == 0) {
                printFizzBuzz();
                i++;
            }
            pthread_mutex_unlock(&lock);  
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (1) {
            pthread_mutex_lock(&lock);
            if (i>n) { pthread_mutex_unlock(&lock); return; }
            if (i%3 != 0 && i%5 != 0) {
                printNumber(i);
                i++;
            }
            pthread_mutex_unlock(&lock); 
        }
    }
};
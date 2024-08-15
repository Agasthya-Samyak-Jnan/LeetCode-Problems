#include <bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/building-h2o/
// Difficulty : Medium

/* CONCURRENCY AND SYNCHRONIZATION IN MULTITHREADING */

/* Initial Brute Force or Simple Direct Solution */
class H2O {
public:
    sem_t h,o;
    int i;
    pthread_mutex_t lock;
    
    H2O() {
        sem_init(&h,0,2);
        sem_init(&o,0,1); 
        pthread_mutex_init(&lock,NULL);
        i = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        
        sem_wait(&h);
        pthread_mutex_lock(&lock);
        i++;
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        if (i%3 == 0) { sem_post(&h); sem_post(&h); sem_post(&o); }
        pthread_mutex_unlock(&lock);
    }

    void oxygen(function<void()> releaseOxygen) {
        
        sem_wait(&o);
        pthread_mutex_lock(&lock);
        i++;
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        if (i%3 == 0) { sem_post(&h); sem_post(&h); sem_post(&o); }
        pthread_mutex_unlock(&lock);
    }
};


#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

// Link to the Problem : https://leetcode.com/problems/print-in-order/
// Difficulty : Easy

/* CONCURRENCY AND SYNCHRONIZATION OF PROCESSES : USING SEMAPHORES */
typedef struct {
   sem_t p1;
   sem_t p2;    
} Foo;

Foo* fooCreate() {
    Foo* obj = (Foo*) malloc(sizeof(Foo));
    sem_init(&obj->p1,0,0);
    sem_init(&obj->p2,0,0);   
    return obj;
}

void first(Foo* obj) {
    printFirst();
    sem_post(&obj->p1);
}

void second(Foo* obj) {
    sem_wait(&obj->p1);
    printSecond();
    sem_post(&obj->p2);
}

void third(Foo* obj) {
    sem_wait(&obj->p2);
    printThird();
}

void fooFree(Foo* obj) {
     sem_destroy(&obj->p1);
     sem_destroy(&obj->p2);
     free(obj);
}
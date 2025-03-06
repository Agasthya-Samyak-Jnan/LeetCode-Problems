#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/design-front-middle-back-queue/
// Difficulty : Medium

/* DOUBLY LINKED LIST - PushMiddle and PopMiddle - Time : O(N/2)  */
class FrontMiddleBackQueue {
    public:
        int n = 0;
        list<int> q;
    
        FrontMiddleBackQueue() {
            
        }
        
        void pushFront(int val) {
            q.push_front(val);
            n++;
        }
        
        void pushMiddle(int val) {
            auto it = q.begin();
            advance(it,n/2);
            q.insert(it,val);
            n++;
        }
        
        void pushBack(int val) {
            q.push_back(val);
            n++;
        }
        
        int popFront() {
            int res = -1; 
            if (!q.empty()) {
                res = q.front();
                q.pop_front();
                n--;
            }
            return res;
        }
        
        int popMiddle() {
            int res = -1;
            if (!q.empty()) {
                auto it = q.begin();
                advance(it,(n-1)/2);
                res = *it;
                q.erase(it);
                n--;
            }
            return res;
        }
        
        int popBack() {
            int res = -1; 
            if (!q.empty()) {
                res = q.back();
                q.pop_back();
                n--;
            }
            return res;
        }
};
#include<bits/stdc++.h>
#include<vector>

using namespace std;

// Link to the Problem: https://leetcode.com/problems/random-flip-matrix/
// Difficulty: Medium

/* NOT BEST SOLUTION (NEEDS SERIOUS IMPROVEMENT) */
class Solution {
    int m, n;
    map<pair<int, int>,int> grid;
public:
    Solution(int m, int n) {
        this->m = m;
        this->n = n;
    }
    
    vector<int> flip() {
        int i = rand() % m;
        int j = rand() % n;

        while(grid[{i,j}] != 0)
        {
            i = rand() % m;
            j = rand() % n;
        }

        grid[{i,j}] = 1;
        return {i,j};
    }
    
    void reset() {
        grid.clear();
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */


/* SOLUTION USING C, BUT TIME LIMIT EXCEEDED FOR 10,000 ELEMENTS */
typedef struct {
    int** a;
    int m;
    int n;
} Solution;


Solution* solutionCreate(int a, int b) {
    Solution* s = (Solution*)malloc(sizeof(Solution));
    s->a = (int**)calloc(a,sizeof(int*));
    for(int i=0;i<a;i++) { 
        *(s->a + i) = (int*)calloc(b,sizeof(int)); 
    }
    s->m = a;
    s->n = b;
    return s;
}

int* solutionFlip(Solution* obj, int* retSize) {
     int i = rand()%(obj->m);
     int j = rand()%(obj->n);
     while (obj->a[i][j] != 0) {
         i = rand()%(obj->m);
         j = rand()%(obj->n);
     }
     *retSize = 2; // RETURN SIZE SHOULD BE RETURNED
     int* ans = (int*)calloc(2,sizeof(int));
     ans[0] = i, ans[1] = j;
     printf("%d %d\n", ans[0], ans[1]);
     obj->a[i][j] = 1;
     return ans;
}

void solutionReset(Solution* obj) {
     for(int i=0;i<(obj->m);i++) {
         memset(obj->a[i],0,4*(obj->n));
     }
}

void solutionFree(Solution* obj) {
     for (int i=0;i<(obj->m);i++) {
         free(obj->a[i]);
     }
     free(obj->a);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(m, n);
 * int* param_1 = solutionFlip(obj, retSize);
 
 * solutionReset(obj);
 
 * solutionFree(obj);
*/
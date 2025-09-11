#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/number-of-people-aware-of-a-secret/
// Difficulty : Medium 

/* DYNAMIC PROGRAMMING = DEPTH-FIRST SEARCH (RECURSION) BUT MORE INTELLIGENT AND OPTIMAL WITH MEMOIZATION */

// /* #1 - PURE RECURSIVE DFS AND ID TRACKING FOR EACH PERSON KNOWING THE SECRET USING A HASHSET */
// class Solution {
// public:
//     int end, delay, forget;
//     unordered_set<long long> knows;
//     long long seq_num = 0;

//     void dfs (long long id, int d, int knows_from) {
//         if (d > end) { return; }
//         if (knows_from == 1) {
//             knows.insert(id);
//         } 
//         if (knows_from > forget) {
//             knows.erase(id); 
//             return;
//         }
//         if (knows_from > delay) {
//             dfs(++seq_num,d,1);
//         }
//         dfs(id,d+1,knows_from+1);
//     }

//     int peopleAwareOfSecret(int n, int delay, int forget) {
//         end = n;
//         this->delay = delay;
//         this->forget = forget;
//         dfs(seq_num,1,1);
//         return knows.size();
//     }
// };

// /* #2 - FIGURED OUT THAT THERE IS NO NEED TO TRACK EXPLICITLY "WHO" KNOWS SECRET ON ANY GIVEN DAY, RATHER WE NEED ONLY "HOW MANY" KNOW THE SECRET. */
// class Solution {
// public:
//     int end, delay, forget;
//     long long seq_num = 0, knows = 1;

//     void dfs (long long id, int d, int knows_from) {
//         if (d > end) { return; }
//         if (knows_from > forget) {
//             knows--;
//             return;
//         }
//         if (knows_from > delay) {
//             knows++;
//             dfs(++seq_num,d+delay,delay+1);
//         }
//         dfs(id,d+1,knows_from+1);
//     }

//     int peopleAwareOfSecret(int n, int delay, int forget) {
//         end = n;
//         this->delay = delay;
//         this->forget = forget;
//         dfs(seq_num,1+delay,delay+1);
//         return knows;
//     }
// };

// /* #3 - UNDERSTOOD THAT 'id' is not needed since we only need "how many" and not exactly "who" knows secret. */
// class Solution {
// public:
//     int end, delay, forget;
//     long long knows = 1;

//     void dfs (int d, int knows_from) {
//         if (d > end) { return; }
//         if (knows_from > forget) {
//             knows--;
//             return;
//         }
//         if (knows_from > delay) {
//             knows++;
//             dfs(d+delay,delay+1);
//         }
//         dfs(d+1,knows_from+1);
//     }

//     int peopleAwareOfSecret(int n, int delay, int forget) {
//         end = n;
//         this->delay = delay;
//         this->forget = forget;
//         dfs(1+delay,delay+1);
//         return knows;
//     }
// };

// /* #4 - Optimization - instead of creating function call for each day, add that delay beforehand since you do same thing each function call. */
// class Solution {
// public:
//     int end, delay, forget;
//     long long knows = 1;

//     void dfs (int d, int knows_from) {
//         if (d > end) { knows--; return; }
//         if (d + forget <= end) { knows--; }
//         for (int i=0;i<forget-delay;i++) {
//             knows++;
//             dfs(d+i+delay,delay+1);
//         }
//     }

//     int peopleAwareOfSecret(int n, int delay, int forget) {
//         end = n;
//         this->delay = delay;
//         this->forget = forget;
//         dfs(1,1);
//         return knows;
//     }
// };

// /* #5 */
// class Solution {
// public:
//     int end, delay, forget;
//     long long knows = 1;

//     void dfs (int d) {
//         if (d > end) { knows--; return; }
//         if (d + forget <= end) { knows--; }
//         for (int i=0;i<forget-delay;i++) {
//             knows++;
//             dfs(d+i+delay);
//         }
//     }

//     int peopleAwareOfSecret(int n, int delay, int forget) {
//         end = n;
//         this->delay = delay;
//         this->forget = forget;
//         dfs(1);
//         return knows;
//     }
// };

// /* #6 */
// class Solution {
// public:
//     int end, delay, forget;

//     long long dfs (int d) {
//         if (d > end) { return -1; }
//         long long knows = 0;
//         if (d + forget <= end) { knows--; }
//         for (int i=0;i<forget-delay;i++) {
//             knows++;
//             knows += dfs(d+i+delay);
//         }
//         return knows;
//     }

//     int peopleAwareOfSecret(int n, int delay, int forget) {
//         end = n;
//         this->delay = delay;
//         this->forget = forget;
//         return 1 + dfs(1);
//     }
// };

// /* #7 */
// class Solution {
// public:
//     int end, delay, forget;
//     unordered_map<int,int> dp;

//     long long dfs (int d) {
//         if (d > end) { return -1; }
//         if (dp.find(d) != dp.end()) { return dp[d]; }
//         long long knows = 0;
//         if (d + forget <= end) { knows--; }
//         for (int i=0;i<forget-delay;i++) {
//             knows++;
//             knows += dfs(d+i+delay);
//         }
//         return dp[d] = knows;
//     }

//     int peopleAwareOfSecret(int n, int delay, int forget) {
//         end = n;
//         this->delay = delay;
//         this->forget = forget;
//         return 1 + dfs(1);
//     }
// };

// /* #8 */
// class Solution {
// public:
//     int end, delay, forget, mod = 1e9 + 7;
//     unordered_map<int,int> dp;

//     int dfs (int d) {
//         if (d > end) { return -1; }
//         if (dp.find(d) != dp.end()) { return dp[d]; }
//         long long knows = -(d + forget <= end);
//         for (int i=0;i<forget-delay;i++) {
//             knows++;
//             knows += dfs(d+i+delay);
//         }
//         return dp[d] = knows % mod;
//     }

//     int peopleAwareOfSecret(int n, int delay, int forget) {
//         end = n;
//         this->delay = delay;
//         this->forget = forget;
//         return 1 + dfs(1);
//     }
// };

/* FINAL BEST OPTIMIZED SOLUTION - RECURSION WITH 1D MEMOIZATION */
class Solution {
public:
    int end, delay, forget, mod = 1e9 + 7;
    vector<int> dp;

    int dfs (int d) {
        if (d > end) { return -1; }
        if (dp[d] != -4) { return dp[d]; }
        long long knows = -(d + forget <= end);
        for (int i=0;i<forget-delay;i++) {
            knows++;
            knows += dfs(d+i+delay);
        }
        return dp[d] = knows % mod;
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        end = n;
        this->delay = delay;
        this->forget = forget;
        dp = vector<int>(1001, -4);
        return 1 + dfs(1);
    }
};

// DRIVER CODE
int main (int argc, char* argv[]) {

    Solution s;
    cout<<s.peopleAwareOfSecret(atoi(argv[1]),atoi(argv[2]),atoi(argv[3]))<<endl;

    return 0;
}
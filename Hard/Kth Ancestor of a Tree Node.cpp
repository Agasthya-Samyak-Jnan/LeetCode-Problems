#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/kth-ancestor-of-a-tree-node/
// Difficulty : Hard

/* PURE RECURSION / DEPTH-FIRST SEARCH - QUERY O(N) , NO PREPROCESSING - TIME LIMIT EXCEEDED - ALL CASE O(N) TIME */
class TreeAncestor {
public:
    vector<int> p;
    int n;
    
    TreeAncestor(int n, vector<int>& parent) {
        p = parent;
        this->n = n;
    }
    
    int getKthAncestor(int node, int k) {
        
        int kthAncestor = node;
        
        while (k && kthAncestor != -1) {
            kthAncestor = p[kthAncestor];
            k--;
        }
        
        return kthAncestor;
    }
};

/* RECURSION + 2D MEMOIZATION - FIRST TIME QUERIES O(N), REPEATED QUERIES O(1), NO PREPROCESSING - TIME LIMIT EXCEEDED - WORST CASE O(N) TIME  */
class TreeAncestor {
public:
    vector<int> p;
    int n;
    unordered_map<int,unordered_map<int,int>> mp;
    
    TreeAncestor(int n, vector<int>& parent) {
        p = parent;
        this->n = n;
    }
    
    int getKthAncestor(int node, int k) {
        
        int kthAncestor = node, K = k;
        
        if (mp.find(node) != mp.end() && mp[node].find(k) != mp[node].end()) { return mp[node][k]; }
        
        while (K && kthAncestor != -1) {
            kthAncestor = p[kthAncestor];
            K--;
        }
        return mp[node][k] = kthAncestor;
    }
};

/* PURE RECURSION / DEPTH-FIRST SEARCH + HASH TABLE - PREPROCESSING O(N*N), QUERY O(1) - MEMORY LIMIT EXCEEDED - WORST CASE O(N^2) SPACE */
class TreeAncestor {
public:

    vector<vector<int>> dp;

    TreeAncestor(int n, vector<int>& parent) {

        dp = vector<vector<int>>(n);

        for (int i=0;i<n;i++) {
            int node = i;
            while (node > 0) {
                node = parent[node];
                dp[i].push_back(node);
            }
        }

    }
    
    int getKthAncestor(int node, int k) {
        return dp[node].size() < k ? -1 : dp[node][k-1];
    }
};

/* RECURSION + 2D MEMOIZATION - BINARY LIFTING METHOD - PREPROCESSING O(N*log2(N)) , QUERY O(log2(k)) - ALL CASE O(log2(k)) TIME, O(N*log2(N)) SPACE */
/*
    BINARY LIFITNG CONCEPT :

    - Instead of checking who is the ancestor by going back through tree 1 node at a time for 'k' nodes, jump 2^x nodes at a time for 'k' nodes.
    - Encode 'k' as "(2^x) Jumps" that can be used to reach 'k'. This can be done by representing 'k' in binary. ('k' as sum of powers of 2).

    - Essence : Instead of making 'x' iterations to reach 'k'th ancestor of a node, by encoding in powers of 2 we only make 'log2(x)' iterations to reach 'k'th ancestor.
      Hence O(log2(k)) time needed. 


    - To make the above jumping process possible, you store (2^x)th ancestors for each node to make the '2^x'th jump.
    - First we store each node's parent (1st Ancestor) normally. Store it as anc[i][0], 'i' is the node, '0' represents 1st Ancestor or parent of 'i' - O(N) time
    - Then we calculate each '2^x'th ancestor for each node, where 'x' ranges from 0 to log2(N) where 'N' is the Total Number of Nodes in Tree.
      If Tree is skewed (i.e looks like a linked list) then we will have upto 'N-1'th ancestors. Hence, maximum power of 2 that is needed to represent 'N-1' is log2(N).

    - We know, 2^x = 2^(x-1) + 2^(x-1). Similarily, '2^x'th ancestor of a node is the node's '2^(x-1)'th ancestor's '2^(x-1)'th acnestor.
      That can be told as : anc[i][j] = anc[anc[i][j-1]][j-1], 
      where anc[i][j] means " (2^j)th Ancestor of node 'i' ", the index 'j' is POWER OF 2.

    - Our 'anc' table will have entries for all 'N' nodes and for all upto 'log2(N)' ancestors of node.
      That is, N times log2(N) Entries in the Table - Hence, O(N*log2(N)) Space needed.
*/
class TreeAncestor {
public:

    vector<vector<int>> anc;

    TreeAncestor(int n, vector<int>& parent) {

        int LIMIT = ceil(log2(n));

        anc = vector<vector<int>>(n, vector<int>(LIMIT,-1));
        
        for (int i=0;i<n;i++) { anc[i][0] = parent[i]; }

        for (int i=0;i<n;i++) {
            for (int j=1;j<LIMIT;j++) {
                if (anc[i][j-1] != -1) {
                    anc[i][j] = anc[anc[i][j-1]][j-1]; // 
                }
            }
        }

    }
    
    int getKthAncestor(int node, int k) {

        int powerof2 = 0, kthAncestor = node;
        
        // Go through 'k' bitwise (i.e through its binary representation of bits)
        while (k > 0 and kthAncestor != -1) { // No Kth Ancestor if we reach -1 (i.e non-existent parent of root node) before we process query completely.
            if (k&1) {
                if (powerof2 > 0) { 
                    if (anc[kthAncestor][powerof2-1] != -1) { kthAncestor = anc[anc[kthAncestor][powerof2-1]][powerof2-1]; }
                    else { return -1; } // No Kth Ancestor
                }
                else { kthAncestor = anc[kthAncestor][0]; }
            }
            powerof2++;
            k = k>>1;
        }

        return kthAncestor;
    }
};

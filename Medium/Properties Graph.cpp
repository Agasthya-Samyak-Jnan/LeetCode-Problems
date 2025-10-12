#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/properties-graph/
// Difficulty : Medium 

/* GRAPH + UNION FIND - Normal Method of finding Unique Number Intersection between Arrays. - 2000ms+ , 400MB+ */

// Union-Finder Disjoint Set (Rank Method + Path Compression)
class UFS {
private:
    // Disjoint Set Data Structures
    int n;
    vector<int> parent;
    vector<int> rank;

public:
    // Initialise Disjoint Set
    UFS (int n) {
        this->n = n;
        parent = vector<int>(n);
        rank = vector<int>(n,0);
        iota(parent.begin(),parent.end(),0);
    }

    // Combine/Union thier Families
    void Union (int a, int b) {  
        int A = find(a), B = find(b);
        if (A == B) { return; }
        if (rank[A] > rank[B]) { parent[B] = A; }
        else {
            if (rank[A] == rank[B]) { rank[B]++; }
            parent[A] = B;
        } 
        n--;
    }

    // Find Upper-Most Parent 
    int find (int a) {  
        return (a == parent[a]) ? a : parent[a] = find(parent[a]);
    }

    // Find Current Number of Components
    int components () { return n; }
};

class Solution {
public:
    int intersect (vector<int>& a, vector<int>& b) {
        unordered_set<int> A(a.begin(),a.end());
        int common_nums = 0;
        for (auto num : b) { if(A.find(num) != A.end()) { common_nums++; A.erase(num); } }
        return common_nums;
    }

    int numberOfComponents(vector<vector<int>>& properties, int k) {
        
        int n = properties.size();
        UFS ufs(n);

        for (int i=0;i<n-1;i++) {
            for (int j=i+1;j<n;j++) {
                if (intersect(properties[i],properties[j]) >= k) { ufs.Union(i,j); }
            }
        }

        return ufs.components();
    }
};

/* Using BitSet Data Structure and Bit Manipulation Methods to Optimize computation of Intersection between Arrays. - ~ 0-5ms, ~ 35MB */
// Union-Finder Disjoint Set (Rank Method + Path Compression)
class UFS {
private:
    // Disjoint Set Data Structures
    int n;
    vector<int> parent;
    vector<int> rank;

public:
    // Initialise Disjoint Set
    UFS (int n) {
        this->n = n;
        parent = vector<int>(n);
        rank = vector<int>(n,0);
        iota(parent.begin(),parent.end(),0);
    }

    // Combine/Union thier Families
    void Union (int a, int b) {  
        int A = find(a), B = find(b);
        if (A == B) { return; }
        if (rank[A] > rank[B]) { parent[B] = A; }
        else {
            if (rank[A] == rank[B]) { rank[B]++; }
            parent[A] = B;
        } 
        n--;
    }

    // Find Upper-Most Parent 
    int find (int a) {  
        return (a == parent[a]) ? a : parent[a] = find(parent[a]);
    }

    // Find Current Number of Components
    int components () { return n; }
};

class Solution {
public:

    int numberOfComponents(vector<vector<int>>& properties, int k) {
        
        int n = properties.size();
        UFS ufs(n);
        vector<bitset<101>> b(n); // Given constraints : 1 <= properties[i][j] <= 100

        for (int i=0;i<n;i++) {
            for (auto num : properties[i]) { b[i].set(num); }
        }

        for (int i=0;i<n-1;i++) {
            for (int j=i+1;j<n;j++) {
                if ((b[i]&b[j]).count() >= k) { ufs.Union(i,j); } // Each bit is used to represent a Number's presence, reduces Time and Space needed to compute intersection by allocating and optimizing during compile time.
            }
        }

        return ufs.components();
    }
};
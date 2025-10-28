#include <bits/stdc++.h>

// Link to the Problem: https://leetcode.com/problems/satisfiability-of-equality-equations/
// Difficulty: Medium

using namespace std; 

/* GRAPH + UNION FIND */
/*
    - Equality in a equation implies left and right entities are same and can be represented by each other.
    - Hence, they can be put in a single group together.
    - When other equality equations refer these entities, they also belong to same group.
    - Not Equal equations tells that two entities can't be represented by each other, Hence they should not be together in a group.
    - We can imagine this as a groups of variables spread across, where variables in same group are equal to one another and vice-versa.
    - So now we need a representation to depcit this idea - use GRAPH concepts.
    - Connected nodes are equal to one another and an equality group is a connected component in equality graph containing many such components.
    - Now we need a method to build such a graph and query if any equations contradict the equality graph built - use UNION FIND (DISJOINT SET UNION)
    - What is Union Find? Pls search on google these things then : Sets in Set Theory, Graphs in Discrete Maths and Union Find Data Structure in Data Structures and Algorithms.
*/

class UFS {
public:
    int n;
    vector<int> parent, rank;

    UFS (int n) {
        parent = vector<int>(n);
        rank = vector<int>(n,0);
        iota(parent.begin(),parent.end(),0);
    }

    bool Union (int a, int b) {
        int A = find(a), B = find(b);
        if (A == B) { return false; }
        if (rank[A] < rank[B]) { parent[A] = B; }
        else {
            if (rank[A] == rank[B]) { rank[A]++; }
            parent[B] = A;
        }
        return true;
    }

    int find (int a) {
        return parent[a] = ((a == parent[a]) ? a : find(parent[a]));
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        
        UFS ufs(26);
        
        for (auto eqn : equations) {
            if (eqn[1] != '!') { ufs.Union(eqn[0]-'a',eqn[3]-'a'); }
        }

        for (auto eqn : equations) {
            if (eqn[1] == '!' and ufs.find(eqn[0]-'a') == ufs.find(eqn[3]-'a')) {
                return false;
            }
        }

        return true; 
    }
};
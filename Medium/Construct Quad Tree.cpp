#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/construct-quad-tree/
// Difficulty : Medium 

/* Quad Tree Node Defintion 

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

*/

/* DIVIDE AND CONQUER + RECURSIVE TREE BUIDLING */
class Solution {
    public:
        vector<vector<int>> g; 
        int n;
    
        Node* build (int L, int R, int U, int D) {
            
            // Invalid Division Case
            if (L > R or U > D) { return nullptr; }
            
            // Leaf Node Case
            if (L == R and U == D) { return new Node(g[U][L],true); }

            int HorizontalMid = (R+L)/2 , VerticalMid = (D+U)/2;
            Node* TL = build(L , HorizontalMid , U , VerticalMid); // Top Left
            Node* TR = build(HorizontalMid + 1 , R , U , VerticalMid); // Top Right
            Node* BL = build(L , HorizontalMid , VerticalMid + 1 , D); // Bottom Left
            Node* BR = build(HorizontalMid + 1 , R , VerticalMid + 1 , D); // Bottom Right
            
            // When a Square or a cell is full of Same Values - merge them into a single Leaf Node.
            if (TL->val == TR->val and BL->val == BR->val and TL->val == BL->val) {
                if (TL->isLeaf and TR->isLeaf and BL->isLeaf and BR->isLeaf) {
                    return new Node(TL->val,true);
                }
            }
            
            // When there are different values in Square.
            return new Node(1,0,TL,TR,BL,BR);
        }
    
        Node* construct(vector<vector<int>>& grid) {
            g = grid;
            n = grid.size();
            return build(0,n-1,0,n-1);
        }
};
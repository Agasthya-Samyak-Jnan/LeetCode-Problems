#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/logical-or-of-two-binary-grids-represented-as-quad-trees/
// Difficulty : Medium 

/* QUAD TREE NODE DEFINITION */
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

/* DIVIDE AND CONQUER - DIVIDE WHEN GRIDS HAVE DIFFERENT VALUES, MERGE WHEN THEY HAVE ALL SAME VALUES */

class Solution {
    public:
        Node* intersect(Node* qt1, Node* qt2) {
    
            // If Both are Leaf Nodes (Both Parts of Grid have same value in all cells)
            if (qt1->isLeaf and qt2->isLeaf) { return new Node((qt1->val|qt2->val),1); }
    
            // If Both are NOT Leaf Nodes (Both Parts of Grid have different values in thier cells)
            else if (!(qt1->isLeaf ^ qt2->isLeaf)) {
                Node* TL = intersect(qt1->topLeft,qt2->topLeft); 
                Node* TR = intersect(qt1->topRight,qt2->topRight); 
                Node* BL = intersect(qt1->bottomLeft,qt2->bottomLeft); 
                Node* BR = intersect(qt1->bottomRight,qt2->bottomRight); 
    
                if (TL->val == TR->val and TR->val == BL->val and BL->val == BR->val) {
                    if (TL->isLeaf and TR->isLeaf and BL->isLeaf and BR->isLeaf) {
                        return new Node(TL->val,1);
                    }
                }
    
                return new Node(1,0,TL,TR,BL,BR);
            }
    
            // If Only one of Two is a Leaf Node (One Grid has all same values, while other has different values)
            // Logical OR always gives 1, if any one of the input is 1. Return the Grid that contains all 1s.
            // Otherwise, return Grid that contains different values.
            else {
                if (qt1->isLeaf) { return qt1->val == 1 ? qt1 : qt2; } // Never assign Input Nodes to Answer Nodes like this in actual applications.
                else { return qt2->val == 1 ? qt2 : qt1; } // Never assign Input Nodes to Answer Nodes like this in actual applications. You are tangling input with output this way.
            }
        }
};
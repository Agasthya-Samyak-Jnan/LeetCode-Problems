#include<stdio.h>
#include<stdlib.h>

//Link to the Problem: https://leetcode.com/problems/delete-node-in-a-linked-list/
//Difficulty: Medium

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* 
 * Delete the given argument 'node' from the Linked List , BUT ITS HEAD WILL NOT BE GIVEN TO YOU 
 * 1. You need NOT to "remove" the node from memory 
 * 2. It should just not exist in the Linked List 
*/

void deleteNode(struct ListNode* node) {
    *node  = *(node->next);  
}
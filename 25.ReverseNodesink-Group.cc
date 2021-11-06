// 25. Reverse Nodes in k-Group
// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

#include "define.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1 || head == nullptr) return head;
        int num = k;
        ListNode* cur = head;
        while (num && cur) {
            cur = cur->next;
            --num;
        }
        if (num > 0) return head;
        ListNode* newHead = nullptr;
        ListNode* lastNode = nullptr;
        cur = head;
        num = k;
        while (num) {
            if (newHead == nullptr) {
                newHead = cur;
                lastNode = cur;
                cur = cur->next;
            } else {
                ListNode* tmp = cur;
                cur = cur->next;
                tmp->next = newHead;
                newHead = tmp;
            }
            --num;
        }
        if (cur) {
            lastNode->next = reverseKGroup(cur, k);
        } else {
            lastNode->next = nullptr;
        }
        return newHead;
    }
};

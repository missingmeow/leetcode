// 24. Swap Nodes in Pairs

// Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* newHead = head->next;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur && cur->next) {
            ListNode* tmp = cur->next->next;
            if (pre) {
                pre->next = cur->next;
            }
            cur->next->next = cur;
            cur->next = tmp;
            pre = cur;
            cur = tmp;
        }
        return newHead;
    }
};

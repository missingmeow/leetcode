// 2. Add Two Numbers
// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* root = nullptr;
        ListNode* next = nullptr;
        bool bIn = false;
        while (t1 || t2) {
            int val{};
            if (t1) {
                val += t1->val;
                t1 = t1->next;
            }
            if (t2) {
                val += t2->val;
                t2 = t2->next;
            }
            if (bIn) val += 1;
            if (val > 9) bIn = true;
            else bIn = false;
            if (root == nullptr) {
                root = new ListNode(val % 10);
                next = root;
            } else {
                next->next = new ListNode(val % 10);
                next = next->next;
            }
        }
        if (bIn) {
            next->next = new ListNode(1);
        }
        return root;
    }
};
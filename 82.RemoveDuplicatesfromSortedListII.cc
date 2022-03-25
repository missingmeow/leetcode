// 82. Remove Duplicates from Sorted List II
// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* root = nullptr;
        ListNode* cur = nullptr;
        int val = head->val;
        bool bDelete = false;
        ListNode* next = head;
        while (next) { // 有一说一，这逻辑虽然对的，但有点难懂啊
            if (!bDelete) {
                if (next->next) {
                    bDelete = val == next->next->val;
                }
                if (bDelete) {
                    ListNode* tmp = next;
                    next = next->next;
                    delete tmp;
                } else {
                    if (root == nullptr) {
                        root = next;
                        cur = next;
                    } else {
                        cur->next = next;
                        cur = cur->next;
                    }
                    next = next->next;
                    val = next->val;
                }
            } else {
                if (next->val == val) {
                    ListNode* tmp = next;
                    next = next->next;
                    delete tmp;
                } else {
                    val = next->val;
                    bDelete = false;
                }
            } 
        }
        if (cur)
            cur->next = nullptr;
        return root;
    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // 使用哨兵节点
        ListNode* root = new ListNode(0, head);
        ListNode* cur = root;
        while (head) {
            if (head->next && head->val == head->next->val) {
                while (head->next && head->val == head->next->val) {
                    ListNode* tmp = head;
                    head = head->next;
                    delete tmp;
                }
                cur->next = head->next;
                delete head;
            } else {
                cur = cur->next;
            }
            head = cur->next;
        }
        cur = root->next;
        delete root;
        return cur;
    }
};

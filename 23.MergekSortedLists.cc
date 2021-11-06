// 23. Merge k Sorted Lists
// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        vector<ListNode*> newLists = lists;
        while (newLists.size() != 1) {
            vector<ListNode*> ls;
            for (int i = 0; i < newLists.size() - 1; ) {
                ListNode* newl = mergesort(newLists[i], newLists[i + 1]);
                ls.push_back(newl);
                i += 2;
            }
            if (newLists.size() & 1) {
                ls.push_back(newLists[newLists.size() - 1]);
            }
            newLists = std::move(ls);
        }
        return newLists[0];
    }
    ListNode* mergesort(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode* head = nullptr;
        if (l1->val > l2->val) {
            head = l2;
            l2 = l2->next;
        } else {
            head = l1;
            l1 = l1->next;
        }
        ListNode* cur = head;
        while (l1 && l2) {
            if (l1->val > l2->val) {
                cur->next = l2;
                l2 = l2->next;
            } else {
                cur->next = l1;
                l1 = l1->next;
            }
            cur = cur->next;
        }
        if (l1) cur->next = l1;
        if (l2) cur->next = l2;
        return head;
    }
};

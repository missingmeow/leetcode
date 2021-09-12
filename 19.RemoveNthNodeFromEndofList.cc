// 19. Remove Nth Node From End of List
// Given the head of a linked list, remove the nth node from the end of the list and return its head.

#include "define.h"
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n <= 0 || head == nullptr) {
            return head;
        }
        ListNode* firstNode = head;
        ListNode* delNode = head;
        ListNode* preNode = nullptr;
        int cur = n;
        while (firstNode) {
            firstNode = firstNode->next;
            if (cur <= 0) {
                preNode = delNode;
                delNode = delNode->next;
            } else {
                cur--;
            }
        }
        if (delNode) {
            if (preNode) {
                preNode->next = delNode->next;
            } else {
                head = head->next;
            }
            delete delNode;
        }
        return head;
    }
};

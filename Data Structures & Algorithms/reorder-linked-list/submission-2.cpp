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
    void reorderList(ListNode* head) {
        if (head->next == nullptr || head->next->next == nullptr) return;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* tail = slow->next;
        slow->next = nullptr;

        // reverse bottom half of the ll
        ListNode* prev = nullptr;
        while (tail != nullptr) {
            ListNode* curr = tail->next;
            tail->next = prev;
            prev = tail;
            tail = curr;
        }
        tail = prev;

        // merge head with tail
        while (tail != nullptr) {
            ListNode* headNext = head->next;
            ListNode* tailNext = tail->next;
            head->next = tail;
            tail->next = headNext;
            head = headNext;
            tail = tailNext;
        }
    }
};

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
        ListNode* fast = head->next;
        ListNode* slow = head;

        while (fast) {
            slow = slow->next;
            if (!fast->next) break;
            fast = fast->next->next;
        }

        ListNode* curr = slow->next;
        ListNode* prev = slow->next = nullptr;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* cursor = head;
        ListNode* first = head->next;
        ListNode* second = prev;
        while (first) {
            if (second) {
                cursor->next = second;
                second = second->next;
                cursor = cursor->next;
            }
            cursor->next = first;
            first = first->next;
            cursor = cursor->next;
        }
    }
};

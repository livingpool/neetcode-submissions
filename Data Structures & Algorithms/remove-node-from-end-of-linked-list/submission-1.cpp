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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        for (int i = 0; i < n; i++) {
            if (fast == nullptr) break;
            fast = fast->next;
        }

        ListNode* prev = slow;
        if (fast != nullptr) {
            while (fast != nullptr) {
                fast = fast->next;
                prev = slow;
                slow = slow->next;
            }
            prev->next = prev->next->next;
        } else {
            return head->next;
        }

        return head;
    }
};


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
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* cursor = dummy;

        while (fast != nullptr) {
            for (int i = 0; i < k; i++) {
                fast = fast->next;
                if (i < k-1 && fast == nullptr) {
                    return dummy->next;
                } else if (i == k-1 && fast == nullptr) {
                    break;
                }
            }

            // reverse k nodes
            ListNode* prev = fast;
            ListNode* nextCursor = cursor->next;
            while (slow != fast) {
                ListNode* tmp = slow->next;
                slow->next = prev;
                prev = slow;
                slow = tmp;
            }

            // attach the reversed ll
            cursor->next = prev;
            cursor = nextCursor;
        }

        return dummy->next;
    }
};

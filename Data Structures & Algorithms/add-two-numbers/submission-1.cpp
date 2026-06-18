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
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        ListNode* prev1;
        ListNode* prev2;
        int carry = 0;

        while (l1 && l2) {
            int val = l1->val + l2->val + carry;
            if (val >= 10) {
                val -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            l1->val = val;
            l2->val = val;
            prev1 = l1;
            prev2 = l2;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode* res;
        if (l1) {
            res = head1;
            while (l1) {
                int val = l1->val + carry;
                if (val >= 10) {
                    val -= 10;
                    carry = 1;
                } else {
                    carry = 0;
                }
                l1->val = val;
                prev1 = l1;
                l1 = l1->next;
            }
            if (carry) {
                prev1->next = new ListNode(1);
            }
        } else {
            res = head2;
            while (l2) {
                int val = l2->val + carry;
                if (val >= 10) {
                    val -= 10;
                    carry = 1;
                } else {
                    carry = 0;
                }
                l2->val = val;
                prev2 = l2;
                l2 = l2->next;
            }
            if (carry) {
                prev2->next = new ListNode(1);
            }
        }

        return res;
    }
};

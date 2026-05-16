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
        ListNode* head;
        ListNode* curr;
        ListNode* prev = nullptr;

        bool carry = false;

        while (l1 != nullptr && l2 != nullptr) {
            int v = l1->val + l2->val;
            if (carry) v += 1;
            curr = new ListNode(v % 10);
            
            if (prev == nullptr) head = curr;
            else prev->next = curr;

            prev = curr;

            if (v / 10 > 0) carry = true;
            else carry = false;

            l1 = l1->next;
            l2 = l2->next;
        }
        
        while (l1 != nullptr || l2 != nullptr) {
            int v;
            if (l1 != nullptr) {
                v = l1->val;
                l1 = l1->next;
            } else {
                v = l2->val;
                l2 = l2->next;
            }

            if (carry) v += 1;

            curr = new ListNode(v % 10);
            prev->next = curr;
            prev = curr;

            if (v / 10 > 0) carry = true;
            else carry = false;
        }

        if (carry) {
            curr = new(ListNode)(1);
            prev->next = curr;
        }

        return head;
    }
};

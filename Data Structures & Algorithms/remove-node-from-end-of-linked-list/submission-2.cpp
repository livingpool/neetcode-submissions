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
        int leng = 0;
        ListNode* cursor = head;
        while (cursor) {
            cursor = cursor->next;
            leng++;
        }
        int target = leng - n;
        if (target == 0) return head->next;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (target) {
            prev = curr;
            curr = curr->next;
            target--;
        }
        prev->next = curr->next;

        return head;
    }
};

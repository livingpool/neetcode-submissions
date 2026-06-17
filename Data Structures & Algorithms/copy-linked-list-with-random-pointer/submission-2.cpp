/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        unordered_map<Node*, Node*> m; // original ptr -> new ptr
        Node* org = head;
        Node* copy = new Node(head->val);
        Node* copyHead = copy;
        m[org] = copy;
        org = org->next;

        while (org != nullptr) {
            copy->next = new Node(org->val);
            copy = copy->next;
            m[org] = copy;
            org = org->next;
        }

        copy = copyHead;
        while (head != nullptr) {
            if (head->random == nullptr) {
                copy->random = nullptr;
            } else {
                copy->random = m[head->random];
            }
            head = head->next;
            copy = copy->next;
        }

        return copyHead;
    }
};

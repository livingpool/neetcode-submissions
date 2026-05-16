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
        
        unordered_map<Node*, Node*> m;

        Node* cursor = head;
        Node* copyHead = new(Node)(head->val);
        Node* copyCursor = copyHead;

        while (cursor != nullptr) {
            m[cursor] = copyCursor;
            if (cursor->next != nullptr) {
                Node* newNode = new(Node)(cursor->next->val);
                copyCursor->next = newNode;
            } else {
                copyCursor->next = nullptr;
            }

            cursor = cursor->next;
            copyCursor = copyCursor->next;
        }

        cursor = head;
        copyCursor = copyHead;
        
        while (cursor != nullptr) {
            Node* r = cursor->random;
            if (r != nullptr) {
                copyCursor->random = m[r];
            } else {
                copyCursor->random = nullptr;
            }

            cursor = cursor->next;
            copyCursor = copyCursor->next;
        }

        return copyHead;
    }
};

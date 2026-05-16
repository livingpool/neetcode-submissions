class PrefixTreeNode {
    public:
        PrefixTreeNode* children[26];
        bool endOfWord;

        PrefixTreeNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            endOfWord = false;
        }
};

class PrefixTree {
private:
    PrefixTreeNode* root;

public:
    PrefixTree() {
        root = new PrefixTreeNode();
    }
    
    void insert(string word) {
        PrefixTreeNode* curr = root;
        for (char c : word) {
            if (curr->children[c - 'a'] == nullptr) {
                curr->children[c - 'a'] = new PrefixTreeNode();
            }
            curr = curr->children[c - 'a'];
        }

        curr->endOfWord = true;
    }
    
    bool search(string word) {
        PrefixTreeNode* curr = root;
        for (char c : word) {
            if (curr->children[c - 'a'] == nullptr) return false;
            curr = curr->children[c - 'a'];
        } 
        return curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        PrefixTreeNode* curr = root;
        for (char c : prefix) {
            if (curr->children[c - 'a'] == nullptr) return false; 
            curr = curr->children[c - 'a'];
        }
        return true;
    }
};

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

class WordDictionary {
private:
    PrefixTreeNode* root;

public:
    WordDictionary() {
        root = new PrefixTreeNode();
    }
    
    void addWord(string word) {
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
        return subSearch(word, curr);
    }

    bool subSearch(string word, PrefixTreeNode* curr) {
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == '.') {
                bool res = false;
                for (int j = 0; j < 26; j++) {
                    if (curr->children[j] != nullptr) {
                        cout << word.substr(i + 1) << endl;
                        res = subSearch(word.substr(i + 1), curr->children[j]);
                    }
                    if (res) return true;
                }
                return res;
            } else {
                if (curr->children[word[i] - 'a'] == nullptr) return false;
                curr = curr->children[word[i] - 'a'];
            }
        }
        return curr->endOfWord;
    }
};

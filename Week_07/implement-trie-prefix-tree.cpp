// 题目描述
// 208. 实现 Trie (前缀树)
// 实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。

struct Node {
    int count = 0;
    vector<Node*> children = vector<Node*>(26, NULL);
};
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* cur = root;
        int iL = word.length();
        for (int i = 0; i < iL; i++) {
            int pos = word[i] - 'a';
            if (cur->children[pos] == NULL)
            {
                cur->children[pos] = new Node();
            }
            cur = cur->children[pos];
            if (i == iL - 1) cur->count += 1;
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* cur = root;
        int iL = word.length();
        for (int i = 0; i < iL; i++) {
            int pos = word[i] - 'a';
            if (cur->children[pos] == NULL)
            {
                return false;
            }
            cur = cur->children[pos];
        }
        return cur->count > 0;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* cur = root;
        int iL = prefix.length();
        for (int i = 0; i < iL; i++) {
            int pos = prefix[i] - 'a';
            if (cur->children[pos] == NULL)
            {
                return false;
            }
            cur = cur->children[pos];
        }
        return true;
    }

private:
    Node* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
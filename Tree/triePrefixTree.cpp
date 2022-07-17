/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
*/

struct TrieNode {
    TrieNode* children[26];
    bool isWord;
    
    TrieNode() {
        isWord = false;
        memset(children, NULL, sizeof(children));
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    ~Trie() {
        clear(root);    
    }
    
    void clear(TrieNode* r) {
        for (int i = 0; i < 26; i++) {
            if (r->children[i])
                clear(r->children[i]);
        }
        delete r;
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (auto& c : word) {
            if (cur->children[c-'a'] == NULL)
                cur->children[c-'a'] = new TrieNode();
            cur = cur->children[c-'a'];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for (auto& c : word) {
            if (cur->children[c-'a'] == NULL)
                return false;
            cur = cur->children[c-'a'];
        }
        return cur && cur->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (auto& c : prefix) {
            if (cur->children[c-'a'] == NULL)
                return false;
            cur = cur->children[c-'a'];
        }
        return cur;
    }
    
    TrieNode* root;
};

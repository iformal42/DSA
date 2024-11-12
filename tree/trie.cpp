#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TrieNode {
  
    TrieNode* child[26];
    bool wordEnd;
    TrieNode() {
        wordEnd = false;
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }
};

// Method to insert a key into the Trie
void insertKey(TrieNode* root, const string& key) {
    TrieNode* curr = root;
    for (char c : key) {
        if (curr->child[c - 'a'] == nullptr) {  
            TrieNode* newNode = new TrieNode();
            curr->child[c - 'a'] = newNode;
        }
      
        curr = curr->child[c - 'a'];
    }

    curr->wordEnd = true;
}

// Method to search a key in the Trie
bool searchKey(TrieNode* root, const string& key) {

    TrieNode* curr = root;

    for (char c : key) {
        if (curr->child[c - 'a'] == nullptr) 
            return false;                
        curr = curr->child[c - 'a'];
    }

    return curr->wordEnd;
}

int main() {
  
    // Create am example Trie
    TrieNode* root = new TrieNode();
    vector<string> arr = 
      {"and", "ant", "do", "geek", "dad", "ball"};
    for (const string& s : arr) {
        insertKey(root, s);
    }

    // One by one search strings
    vector<string> searchKeys = {"do", "gee", "bat"};
    for (string& s : searchKeys) {
        cout << "Key : " << s << "\n";
        if (searchKey(root, s)) 
            cout << "Present\n";
        else 
            cout << "Not Present\n";        
    }
  
    return 0;
}

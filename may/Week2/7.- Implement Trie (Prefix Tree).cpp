// compile & run: g++ main.cpp -o main && ./main < input.txt > out.txt
// Problem Url:
//
// © Jose Garfias Lopez
//

#include <bits/stdc++.h>

using namespace std;

const int ALPHABET_SIZE = 26;

class TrieNode {
    public:
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord = false;
    
    TrieNode() {
        for (int i=0; i<ALPHABET_SIZE; i++) {
            children[i] = NULL;
        }
    }
};
    
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode(); 
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        
        for (int i=0; i<word.length(); i++) {
            int index = word[i] - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        
        for (int i=0; i<word.length(); i++) {
            int index = word[i] - 'a';
            if (!node->children[index]) {
                return false;
            }
            node = node->children[index];
        }
        return (node != NULL && node->isEndOfWord);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        int steps = 0;
        
        for (int i=0; i<prefix.length(); i++) {
            int index = prefix[i] - 'a';
            if (!node->children[index]) {
                return false;
            } else {
                steps++;
            }
            node = node->children[index];
        }
        return (steps == prefix.length());
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
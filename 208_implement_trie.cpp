/*******************************************************************************
 *  @File  : 208_implement_trie.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Thu 28 Jul 2016 09:08:01 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Implement a trie with insert, search, and startsWith methods.
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 *
 * Your Trie object will be instantiated and called as such:
 * Trie trie;
 * trie.insert("somestring");
 * trie.search("key");
 *
 */

#include <iostream>
#include <unordered_map>

using namespace std;


class TrieNode
{
public:
    // Initialize your data structure here.
    TrieNode() {
        isEnd = false;
    }

    bool hasChild(char child)
    {
        return (children.find(child) != children.end());
    }

    TrieNode* getChild(char child)
    {
        if (children.find(child) == children.end())
            return NULL;
        else
            return children[child];
    }

    void insertChild(char key, TrieNode* child)
    {
        if (!this->hasChild(key))
            children[key] = child;
    }

    unordered_map<char, TrieNode*> children;
    bool isEnd;
};

class Trie {
public:
    Trie()
    {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word)
    {
        TrieNode* current = root;
        for (int i = 0; i < word.length(); ++i)
        {
            if (!(current->hasChild(word[i])))
            {
                TrieNode* child = new TrieNode();
                current->insertChild(word[i], child);
            }
            current = current->getChild(word[i]);
            if (i == word.length() - 1)
                current->isEnd = true;
        }
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* current = root;
        for (int i = 0; i < word.length(); ++i)
        {
            if (!current->hasChild(word[i]))
                return false;
            current = current->getChild(word[i]);
        }
        if (current->isEnd)
            return true;
        else
            return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* current = root;
        for (int i = 0; i < prefix.length(); ++i)
        {
            if (!current->hasChild(prefix[i]))
                return false;
            current = current->getChild(prefix[i]);
        }
        return true;
    }

private:
    TrieNode* root;
};

int main()
{
    Trie trie;
    trie.insert("ABC");
    trie.insert("AB");
    trie.insert("AC");
    trie.insert("CD");
    
    cout<<trie.search("AB")<<endl;
    cout<<trie.search("ABC")<<endl;
    cout<<trie.search("AC")<<endl;
    cout<<trie.startsWith("A")<<endl;
    cout<<trie.search("D")<<endl;
    cout<<trie.search("A")<<endl;
    
    return 0;
}

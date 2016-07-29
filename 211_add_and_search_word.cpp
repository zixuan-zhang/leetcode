/*******************************************************************************
 *  @File  : 211_add_and_search_word.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Fri 29 Jul 2016 09:34:30 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Design a data structure that supports the following two operations:
 *
 * void addWord(word)
 * bool search(word)
 * search(word) can search a literal word or a regular expression string
 * containing only letters a-z or .. A . means it can represent any one letter.
 *
 * For example:
 *
 * addWord("bad")
 * addWord("dad")
 * addWord("mad")
 * search("pad") -> false
 * search("bad") -> true
 * search(".ad") -> true
 * search("b..") -> true
 *
 */

#include <iostream>

using namespace std;

struct Node
{
    bool isEnd;
    Node* array[26];
    Node() {
        for (int i = 0; i < 26; ++i)
            array[i] = NULL;
        isEnd = false;
    }
};

class WordDictionary {
public:
    WordDictionary()
    {
        root = new Node();
    }
    void addWord(string word)
    {
        Node* current = root;
        for (int i = 0; i < word.length(); ++i)
        {
            if (current->array[word[i]-'a'] == NULL)
            {
                Node* node = new Node();
                current->array[word[i]-'a'] = node;
            }
            current = current->array[word[i]-'a'];
            if (i == word.length()-1)
                current->isEnd = true;
        }
    }

    bool _search(Node* node, string word, int step)
    {
        if (NULL == node)
            return false;
        if (step == word.length())
            return node->isEnd;
        if (word[step] != '.')
            return (node->array[word[step]-'a'] != NULL) && _search(node->array[word[step]-'a'], word, step+1);
        else
        {
            for (int i = 0; i < 26; ++i)
            {
                if (node->array[i] != NULL && _search(node->array[i], word, step+1))
                    return true;
            }
            return false;
        }
    }

    bool search(string word) {
        return _search(root, word, 0);
    }

private:
    Node* root;
};


int main()
{
    WordDictionary dic;
    dic.addWord("bad");
    dic.addWord("dad");
    dic.addWord("mad");
    cout<<dic.search("pad")<<endl;
    cout<<dic.search("bad")<<endl;
    cout<<dic.search(".ad")<<endl;
    cout<<dic.search("b..")<<endl;
    return 0;
}

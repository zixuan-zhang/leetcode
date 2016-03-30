/*******************************************************************************
 *  @File  : 127_word_ladder.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sat 27 Feb 2016 08:18:48 PM CST
 ******************************************************************************/

/*
 *
 *
 */

#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool isLadder(string s1, string s2)
    {
        if (s1.length() != s2.length())
        	return false;
        int count = 0;
        for (int i = 0; i < s1.length(); ++i)
        {
        	if (s1[i] != s2[i])
                count++;
        }
        return count == 1;
    }

    void findMinPath(unordered_map<string, int>& strings, unordered_map<string, vector<string> >& ladders, int step,
        string current, int& minLen, string endWord)
    {
        vector<string> follows = ladders[current];
        if (follows.size() == 0)
            return;
        for (int i = 0; i < follows.size(); ++i)
        {
            if (follows[i] == endWord)
            {
                minLen = min(minLen, step+1);
                return;
            }
            if (strings[follows[i]] == 0 && step+2 < minLen)
            {
                strings[follows[i]] = 1;
                findMinPath(strings, ladders, step+1, follows[i], minLen, endWord);
                strings[follows[i]] = 0;
            }
        }
    }

    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        unordered_map<string, vector<string> > ladders;
        wordList.insert(beginWord);
        wordList.insert(endWord);
        unordered_map<string, int> strings;

        for (unordered_set<string>::iterator from = wordList.begin(); from != wordList.end(); ++from)
        {
            strings[*from] = 0;
            for (unordered_set<string>::iterator to = from; to != wordList.end(); ++to)
            {
                if (isLadder(*from, *to))
                {
                    ladders[*from].push_back(*to);
                    ladders[*to].push_back(*from);
                }
            }
        }

        for (unordered_map<string, vector<string> >::iterator it = ladders.begin(); it != ladders.end(); ++it)
        {
            cout<<it->first<<" : ";
            for (int i = 0; i < it->second.size(); ++i)
                cout<<it->second[i]<<" ";
            cout<<endl;
        }

        int minLen = INT_MAX;
        strings[beginWord] = 1;
        string current = beginWord;
        findMinPath(strings, ladders, 1, current, minLen, endWord);
        return minLen == INT_MAX ? 0 : minLen;
    }

    void addFollows(string current, unordered_set<string>& wordList, queue<string>& layerWords)
    {
        wordList.erase(current);
        for (int i = 0; i < current.length(); ++i)
        {
            char letter = current[i];
            for (int j = 0; j < 26; ++j)
            {
                current[i] = j + 'a';
                if (wordList.find(current) != wordList.end())
                {
                    layerWords.push(current);
                    wordList.erase(current);
                }
            }
            current[i] = letter;
        }
    }

    int ladderLengthWithBFS(string beginWord, string endWord, unordered_set<string> wordList)
    {
        wordList.insert(endWord);
        int minLen = 0;
        string current = beginWord;
        queue<string> layerWords;
        layerWords.push(current);
        while (!layerWords.empty())
        {
            int layerSize = layerWords.size();
            while (layerSize)
            {
                string current = layerWords.front();
                layerWords.pop();
                wordList.erase(current);
                if (current == endWord)
                    return minLen + 1;
                addFollows(current, wordList, layerWords);
                layerSize--;
            }
            minLen++;
        }
        return 0;
    }

};

int main()
{
    //string beginWord = "qa";
    //string endWord = "sq";
    //string words[95] = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};

    unordered_set<string> wordList;
    for (auto word:words)
        wordList.insert(word);

    Solution s;
    int len = s.ladderLengthWithBFS(beginWord, endWord, wordList);
    cout<<len<<endl;
    return 0;
}

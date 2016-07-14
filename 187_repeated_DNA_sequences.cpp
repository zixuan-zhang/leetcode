/*******************************************************************************
 *  @File  : 187_repeated_DNA_sequences.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Tue 12 Jul 2016 09:55:27 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T,
 * for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to
 * identify repeated sequences within the DNA.
 *
 * Write a function to find all the 10-letter-long sequences (substrings)
 * that occur more than once in a DNA molecule.
 *
 * For example,
 *
 * Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
 *
 * Return:
 * ["AAAAACCCCC", "CCCCCAAAAA"].
 *
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> result;
        unordered_map<string, int> counter;
        int start = 0;
        while (start + 10 <= s.length())
        {
            string subString = s.substr(start, 10);
            counter[subString] = counter[subString] + 1;
            start++;
        }

        for (unordered_map<string, int>::iterator it = counter.begin(); it != counter.end(); ++it)
        {
            if (it->second > 1)
                result.push_back(it->first);
        }

        return result;
    }
};

int main()
{
    Solution solution;
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> result = solution.findRepeatedDnaSequences(s);
    for (int i = 0; i < result.size(); ++i)
        cout<<result[i]<<endl;
}

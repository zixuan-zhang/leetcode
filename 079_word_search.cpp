/*******************************************************************************
 *  @File  : 079_word_search.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Tue 05 Jan 2016 07:50:23 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring.
 * The same letter cell may not be used more than once.
 *
 * For example,
 * Given board =
 *
 * [
 *   ['A','B','C','E'],
 *   ['S','F','C','S'],
 *   ['A','D','E','E']
 * ]
 * word = "ABCCED", -> returns true,
 * word = "SEE", -> returns true,
 * word = "ABCB", -> returns false.
 *
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    bool findOne(vector<vector<char> >& board, string word, bool** used,
        int x, int y, int index)
    {
        if (index == word.length()-1 && word[index] == board[x][y])
            return true;
        if (word[index] != board[x][y])
            return false;
        int row = board.size();
        int col = board[0].size();
        bool result = false;
        for (int xgap = -1; xgap <= 1; xgap += 2)
        {
            if (x+xgap >= 0 && x+xgap < row && !used[x+xgap][y])
            {
                used[x+xgap][y] = true;
                result |= findOne(board, word, used, x+xgap, y, index+1);
                used[x+xgap][y] = false;
                if (result)
                    return true;
            }
        }
        for (int ygap = -1; ygap <= 1; ygap += 2)
        {
            if (y+ygap >= 0 && y+ygap < col && !used[x][y+ygap])
            {
                used[x][y+ygap] = true;
                result |= findOne(board, word, used, x, y+ygap, index+1);
                used[x][y+ygap] = false;
                if (result)
                    return true;
            }
        }
        return result;
    }
    
    bool exist(vector<vector<char> >& board, string word) {
        if ("" == word)
            return true;
        int row = board.size();
        if (0 == row)
            return false;
        int col = board[0].size();
        bool result = false;
        bool** used = new bool*[row];
        // initialize
        for (int i = 0; i < row; ++i)
            used[i] = new bool[col]();
            
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (board[i][j] == word[0])
                {
                    used[i][j] = true;
                    result = findOne(board, word, used, i, j, 0);
                    if (result)
                        return true;
                    used[i][j] = false;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution s;

    char row1[] = {'A', 'B', 'C', 'E'};
    char row2[] = {'S', 'F', 'C', 'S'};
    char row3[] = {'A', 'D', 'E', 'E'};

    vector<vector<char> > board;
    vector<char> r1;
    vector<char> r2;
    vector<char> r3;
    for (int i = 0; i < 4; ++i)
    {
        r1.push_back(row1[i]);
        r2.push_back(row2[i]);
        r3.push_back(row3[i]);
    }
    board.push_back(r1);
    board.push_back(r2);
    board.push_back(r3);

    bool result = s.exist(board, "ABCB");
    cout<<result<<endl;

    return 0;
}

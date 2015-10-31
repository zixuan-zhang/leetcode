/*******************************************************************************
 *  @File  : 036_valid_soduku.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月31日 星期六 19时03分47秒
 ******************************************************************************/

/*
 * Question:
 *
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 * The Sudoku board could be partially filled, where empty cells are filled
 * with the character '.'.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    /*
     * Solution:
     *
     * 使用暴力的方法
     *
     */

    bool is_valid(int x, int y, int index, vector<vector<bool> >& row,
            vector<vector<bool> >& column, vector<vector<bool> >& sub)
    {
        return (!row[x][index] && !column[y][index] && !sub[(x/3)*3+y/3][index]);
    }

    // 这个方法判定的是这个partitially filled数独能否被solve，不符题意。不过更具
    // 代表性。一开始把一题理解错了，还以为去求solvable的suduku
    bool is_valid_suduku(vector<vector<char> >& board, int x, int y,
            vector<vector<bool> >& row, vector<vector<bool> >& column,
            vector<vector<bool> >& sub)
    {
        //cout<<x<<" "<<y<<endl;
        //if (x < 0 || x >= 9 || y < 0 || y >= 9)
        if (x >= 9)
            return true;
        if (board[x][y] != '.')
        {
            int index = board[x][y] - '1';
            //if (!row[x][index] && !column[y][index] && !sub[(x/3)*3+y/3][index])
            if (is_valid(x, y, index, row, column, sub))
            {
                row[x][index] = true;
                column[y][index] = true;
                sub[(x/3)*3+y/3][index] = true;
                if (8 != y)
                    return is_valid_suduku(board, x, y+1, row, column, sub);
                else
                    return is_valid_suduku(board, x+1, 0, row, column, sub);
            }
            return false;
        }
        else
        {
            //if this cell could be 1-9
            bool result = false;
            for (int index = 0; index <= 8; ++index)
            {
                if (is_valid(x, y, index, row, column, sub))
                {
                    row[x][index] = true;
                    column[y][index] = true;
                    sub[(x/3)*3+y/3][index] = true;
                    if (8 != y)
                        result |= is_valid_suduku(board, x, y+1, row, column, sub);
                    else
                        result |= is_valid_suduku(board, x+1, 0, row, column, sub);
                    //speed up! if result is true, return directly
                    if (result)
                    {
                        board[x][y] = '1' + index;
                        return true;
                    }
                    row[x][index] = false;
                    column[y][index] = false;
                    sub[(x/3)*3+y/3][index] = false;
                }
            }
            return result;
        }
    }

    bool is_valid_suduku2(vector<vector<char> >& board, int x, int y,
            vector<vector<bool> >& row, vector<vector<bool> >& column,
            vector<vector<bool> >& sub)
    {
        if (x >= 9)
            return true;
        if (board[x][y] != '.')
        {
            int index = board[x][y] - '1';
            //if (!row[x][index] && !column[y][index] && !sub[(x/3)*3+y/3][index])
            if (is_valid(x, y, index, row, column, sub))
            {
                row[x][index] = true;
                column[y][index] = true;
                sub[(x/3)*3+y/3][index] = true;
                if (8 != y)
                    return is_valid_suduku2(board, x, y+1, row, column, sub);
                else
                    return is_valid_suduku2(board, x+1, 0, row, column, sub);
            }
            return false;
        }
        else
        {
            if (8 != y)
                return is_valid_suduku2(board, x, y+1, row, column, sub);
            else
                return is_valid_suduku2(board, x+1, 0, row, column, sub);
        }
    }

    bool isValidSuduku(vector<vector<char> >& board)
    {
        vector<vector<bool> >row(9);
        vector<vector<bool> >column(9);
        vector<vector<bool> >sub(9);
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                row[i].push_back(false);
                column[i].push_back(false);
                sub[i].push_back(false);
            }
        }
        return is_valid_suduku2(board, 0, 0, row, column, sub);
    }
};

int main()
{
    char board_c[9][9] = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };
    /*
    char board_c[9][9] = {
        {'4','6','3','7','2','8','9','5','1'},
        {'2','5','9','4','6','1','7','3','8'},
        {'7','8','1','3','5','9','6','4','2'},
        {'5','3','2','1','9','7','4','8','6'},
        {'9','1','4','6','8','2','5','7','3'},
        {'6','7','8','5','4','3','1','2','9'},
        {'8','2','6','9','7','5','3','1','4'},
        {'1','4','7','2','3','6','8','9','5'},
        {'3','9','5','8','1','4','2','6','7'},
    };
    */

    vector<vector<char> >board;
    for (int i = 0; i < 9; ++i)
    {
        vector<char> row;
        for (int j = 0; j < 9; j++)
            row.push_back(board_c[i][j]);
        board.push_back(row);
    }

    Solution s;
    bool result = s.isValidSuduku(board);
    cout<<result<<endl;

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}

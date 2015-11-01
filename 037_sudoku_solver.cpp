/*******************************************************************************
 *  @File  : 037_sudoku_solver.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月31日 星期六 21时26分17秒
 ******************************************************************************/

/*
 * Question:
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * Empty cells are indicated by the character '.'.
 * You may assume that there will be only one unique solution.
 *
 */

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class Solution
{
public:
    bool is_valid(int x, int y, int index, vector<vector<int> >& row,
            vector<vector<int> >& column, vector<vector<int> >& sub)
    {
        return (!row[x][index] && !column[y][index] && !sub[(x/3)*3+y/3][index]);
    }

    int is_valid_suduku(vector<vector<char> >& board, int x, int y)
    {
        if (x >= 9)
            return 1;
        if (board[x][y] != '.')
        {
            int index = board[x][y] - '1';
            int result;
            if (8 != y)
                result = is_valid_suduku(board, x, y+1);
            else
                result = is_valid_suduku(board, x+1, 0);
            return result;
        }
        else
        {
            //if this cell could be 1-9
            int result = 0;
            for (int index = 0; index <= 8; ++index)
            {
                if (!row[x][index] && !column[y][index] && !sub[(x/3)*3+y/3][index])
                {
                    row[x][index] = 1;
                    column[y][index] = 1;
                    sub[(x/3)*3+y/3][index] = 1;
                    if (8 != y)
                        result |= is_valid_suduku(board, x, y+1);
                    else
                        result |= is_valid_suduku(board, x+1, 0);
                    //speed up! if result is true, return directly
                    if (result)
                    {
                        board[x][y] = '1' + index;
                        return 1;
                    }
                    row[x][index] = 0;
                    column[y][index] = 0;
                    sub[(x/3)*3+y/3][index] = 0;
                }
            }
            return result;
        }
    }
    void solveSudoku(vector<vector<char> >& board)
    {

        memset(column,false,sizeof(column));
        memset(row,false,sizeof(row));
        memset(sub,false,sizeof(sub));
        for(int i = 0; i < 9;i++){
            for(int j = 0; j < 9;j++){
                if(board[i][j] == '.')   continue;
                int temp = 3*(i/3)+j/3;
                int num = board[i][j]-'1';
                column[j][num] = row[i][num] = sub[temp][num] = true;
            }
        }

        is_valid_suduku(board, 0, 0);
    }

    bool column[9][9], row[9][9], sub[9][9];
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
    vector<vector<char> >board;
    for (int i = 0; i < 9; ++i)
    {
        vector<char> row;
        for (int j = 0; j < 9; j++)
            row.push_back(board_c[i][j]);
        board.push_back(row);
    }

    Solution s;
    s.solveSudoku(board);

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}

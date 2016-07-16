/*******************************************************************************
 *  @File  : 200_number_of_islands.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sat 16 Jul 2016 05:48:32 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges
 * of the grid are all surrounded by water.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:

    void tranverse(vector<vector<char> >& grid, vector<vector<int> >& visited,
            int i, int j, int rowSize, int columnSize)
    {
        visited[i][j] = 1;
        if (i-1 >= 0 && grid[i-1][j] == '1' && visited[i-1][j] == 0)
            tranverse(grid, visited, i-1, j, rowSize, columnSize);
        if (i+1 < rowSize && grid[i+1][j] == '1' && visited[i+1][j] == 0)
            tranverse(grid, visited, i+1, j, rowSize, columnSize);
        if (j-1 >= 0 && grid[i][j-1] == '1' && visited[i][j-1] == 0)
            tranverse(grid, visited, i, j-1, rowSize, columnSize);
        if (j+1 < columnSize && grid[i][j+1] == '1' && visited[i][j+1] == 0)
            tranverse(grid, visited, i, j+1, rowSize, columnSize);
    }

    int numIslands(vector<vector<char> >& grid)
    {
        if (grid.size() == 0)
            return 0;

        int result = 0;
        int rowSize = grid.size();
        int columnSize = grid[0].size();

        vector<vector<int> > visited;

        for (int i = 0; i < rowSize; ++i)
        {
            vector<int> row(columnSize, 0);
            visited.push_back(row);
        }

        for (int i = 0; i < rowSize; ++i)
        {
            for (int j = 0; j < columnSize; ++j)
            {
                if (grid[i][j] == 1 && visited[i][j] == 0)
                {
                    result++;
                    tranverse(grid, visited, i, j, rowSize, columnSize);
                }
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}

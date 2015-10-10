/*******************************************************************************
 *  @File  : 006_zigzag_conversion.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月09日 星期五 18时50分40秒
 ******************************************************************************/

/*
 * Question:
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 *
 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 *
 */

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    void coor(int layer, int index, int& j, int& i)
    {
        int tour = 2 * layer - 2;
        int a = index / tour; // 多少次
        int b = index % tour;

        if (b == 0)
        {
            a = a -1;
            b = 2 * layer - 2;
        }
        
        int c = b / layer;
        int d = b % layer;


        if (c == 0)
        {
            i = (layer-1) * a;
            j = d - 1;
        }
        else
        {
            i = (layer-1)*a + d;
            j = layer - d - 1;
        }
    }

    string convert(string s, int numRows)
    {
        if ("" == s || numRows == 1)
            return s;
        int len = s.length();
        char** image = new char*[numRows];
        int row, col;
        coor(numRows, len, row, col);
        col += 1;
        cout<<col<<endl;
        for (int i = 0; i < numRows; ++i)
        {
            image[i] = new char[col];
        }

        for (int i = 0; i < numRows; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                image[i][j] = '\0';
            }
        }
        for (int i = 0; i < len; ++i)
        {
            int x, y;
            coor(numRows, i+1, x, y);
            image[x][y] = s[i];
        }
        string res = "";
        for (int i = 0; i < numRows; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (image[i][j] != '\0')
                    res += image[i][j];
            }
        }
        return res;
    }

    // TODO: implement this algorithm
    string convert1(string s, int numRows)
    {
        if ("" == s || numRows == 1)
            return s;
        int len = s.length();
        vector<int>* image = new vector<int>[numRows];
        int* count = new int[numRows];
        for (int i = 0; i < len; ++i)
        {
            int x, y;
            coor(numRows, i+1, x, y);
            count[x] ++;
            image[x].push_back(y);
        }
        string res = resize(len);
        for (int i = 0; i < numRows; ++i)
        {
            for (int j = 0; j < image[i].size(); ++j)
            {
                int cnt = 0;
                for (int k = 0; k < i; k++)
                    cnt += count[k];
                int index = cnt + j;
            }
        }
        // UnFINISHED
    }
};

int main()
{
    Solution s;
    string res = s.convert("PAYPALISHIRING", 3);
    cout<<res<<endl;
    return 0;
}

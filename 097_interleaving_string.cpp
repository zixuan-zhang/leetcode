/*******************************************************************************
 *  @File  : 097_interleaving_string.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2016年03月21日 星期一 21时10分01秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 *
 * For example,
 * Given:
 * s1 = "aabcc",
 * s2 = "dbbca",
 *
 * When s3 = "aadbbcbcac", return true.
 * When s3 = "aadbbbaccc", return false.
 *
 */


class Solution
{
public:

    bool isInter(string s1, int start1, string s2, int start2, string s3, int start3)
    {
        if (s3.length() == start3)
            return true;
        bool result = false;
        if (start1 < s1.length() && s1[start1] == s3[start3])
            result = isInter(s1, start1+1, s2, start2, s3, start3+1);
        if (result)
            return result;
        if (start2 < s2.length() && s2[start2] == s3[start3])
            result = isInter(s1, start1, s2, start2+1, s3, start3+1);
        return result;
    }

    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.length() + s2.length() != s3.length())
            return false;
        int start1 = 0;
        int start2 = 0;
        int start3 = 0;
        return isInter(s1, start1, s2, start2, s3, start3);
    }

    bool isInterleaveWithStack(string s1, string s2, string s3)
    {
        if (s1.length()+s2.length() != s3.length())
            return false;

        vector<int> vec(s3.length());

        stack<int> stack1;
        stack<int> stack2;
        stack<int> stack3;
        bool res = false;
        if (s1.length() > 0 && s1[0] == s3[0])
        {
            stack1.push(1);
            stack2.push(0);
            stack3.push(1);
            res = true;
        }

        if (s2.length() >0 && s2[0] == s3[0])
        {
            stack1.push(0);
            stack2.push(1);
            stack3.push(1);
            res = true;
        }
        if (!res)
            return false;

        int index1, index2, index3;
        while (!stack3.empty())
        {
            index1 = stack1.top();
            index2 = stack2.top();
            index3 = stack3.top();
            stack1.pop();
            stack2.pop();
            stack3.pop();
            if (index3 == s3.length())
                return true;
            if (index1 < s1.length() && s1[index1] == s3[index3])
            {
                stack1.push(index1+1);
                stack2.push(index2);
                stack3.push(index3+1);
            }
            if (index2 < s2.length() && s2[index2] == s3[index3])
            {
                stack1.push(index1);
                stack2.push(index2+1);
                stack3.push(index3+1);
            }
        }
        return false;
    }

    bool isInterleavingWithDP(string s1, string s2, string s3)
    {
        if (s1.length()+s2.length() != s3.length())
            return false;
        if (s1.length() == 0)
            return s2 == s3;
        if (s2.length() == 0)
            return s1 == s3;

        int len1 = s1.length();
        int len2 = s2.length();

        vector<vector<int> > matrix;
        vector<int> vec(len2+1, 1);
        for (int i = 0; i < len1+1; ++i)
            matrix.push_back(vec);

        // initialize
        for (int i = 1; i <= len1; ++i)
            matrix[i][0] = (matrix[i-1][0] && s1[i-1] == s3[i-1]);
        for (int i = 1; i <= len2; ++i)
            matrix[0][i] = (matrix[0][i-1] && s2[i-1] == s3[i-1]);

        for (int i = 1; i <= len1; ++i)
        {
            for (int j = 1; j <= len2; ++j)
            {
                matrix[i][j] = (matrix[i-1][j] && s1[i-1] == s3[i+j-1]) ||
                    (matrix[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }
        return matrix[len1][len2];
    }
};


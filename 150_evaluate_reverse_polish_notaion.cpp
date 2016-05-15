/*******************************************************************************
 *  @File  : 15_evaluate_reverse_polish_notation.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sun 15 May 2016 02:41:09 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 *
 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 *
 * Some examples:
 *   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 *   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 *
 */

#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Solution
{
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<string> container;
        for (int i = 0; i < tokens.size(); ++i)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int value;
                int value1 = atoi(container.top().c_str());
                container.pop();
                string value2 = atoi(container.top().c_str());
                container.pop();
                if (tokens[i] == "+")
                    value = value1 + value2;
                else if (tokens[i] == "-")
                    value = value2 - value1;
                else if (tokens[i] == "*")
                    value = value1 * value2;
                else
                    value = value2 / value1;
                container.push(to_string(value));
            }
            else
                container.push(tokens[i]);
        }
        string res = container.top();
        return atoi(res.c_str());
    }
};

int main()
{
    return 0;
}

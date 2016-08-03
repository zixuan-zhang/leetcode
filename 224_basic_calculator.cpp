/*******************************************************************************
 *  @File  : 224_basic_calculator.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Tue 02 Aug 2016 11:00:37 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Implement a basic calculator to evaluate a simple expression string.
 * The expression string may contain open ( and closing parentheses ), the plus
 * + or minus sign -, non-negative integers and empty spaces .
 * You may assume that the given expression is always valid.
 *
 * Some examples:
 * "1 + 1" = 2
 * " 2-1 + 2 " = 3
 * "(1+(4+5+2)-3)+(6+8)" = 23
 *
 */

#include <iostream>
#include <stack>

using namespace std;

enum TokenType
{
    integer = 0,
    symbol = 1
};

struct Token
{
    TokenType type;
    char symbol;
    int value;
};

class Solution
{
public:
    Token* getToken()
    {
        Token* token = NULL;
        while (index < s.length() && s[index] == ' ')
            index++;
        if (index < s.length() && (s[index] == '(' || s[index] == ')' || s[index] == '+' || s[index] == '-'))
        {
            token = new Token();
            token->type = symbol;
            token->symbol = s[index];
            index++;
        }
        else if (index < s.length() && (s[index] >= '0' && s[index] <= '9') )
        {
            token = new Token();
            token->type = integer;
            int value = s[index] - '0';
            index++;
            while (index < s.length() && s[index] >= '0' && s[index] <= '9')
            {
                value = value * 10 + s[index] - '0';
                index++;
            }
            token->type = integer;
            token->value = value;
            
        }
        return token;
    }

    int calculate(string s) {
        this->s = s;
        index = 0;
        stack<int> values;
        stack<char> operators;

        Token* token;
        while (token = getToken())
        {
            if (token->type == integer)
            {
                if (!operators.empty() && operators.top() == '+')
                {
                    int value1 = values.top();
                    values.pop();
                    values.push(token->value + value1);
                    operators.pop();
                }
                else if (!operators.empty() && operators.top() == '-')
                {
                    int value1 = values.top();
                    values.pop();
                    values.push(value1 - token->value);
                    operators.pop();
                }
                else
                {
                    values.push(token->value);
                }
            }
            else if (token->type == symbol)
            {
                if (token->symbol == '+' || token->symbol == '-' || token->symbol == '(')
                    operators.push(token->symbol);
                else
                {
                    if (!operators.empty() && operators.top() == '(')
                        operators.pop();
                    while (!operators.empty() && (operators.top() == '+' || operators.top() == '-'))
                    { 
                        int value1 = values.top();
                        values.pop();
                        int value2 = values.top();
                        values.pop();
                        if (operators.top() == '+')
                            values.push(value1 + value2);
                        else
                            values.push(value2 - value1);
                        operators.pop();
                    }
                }
            }
        }
        return values.top();
    }

private:
    string s;
    int index;
};

int main()
{
    Solution s;
    // int result = s.calculate("(1+(11) + 13+ ( 1+1+(2-(3))))");
    // int result = s.calculate("((1+1)-1)-(1+1)");
    int result = s.calculate("(1+(4+5+2)-3)+(6+8)");
    cout<<result<<endl;
    return 0;
}

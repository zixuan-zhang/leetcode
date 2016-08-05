/*******************************************************************************
 *  @File  : 227_basic_calculator_ii.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Wed 03 Aug 2016 09:27:32 PM CST
 ******************************************************************************/

/*
 * 
 * Implement a basic calculator to evaluate a simple expression string.
 * The expression string contains only non-negative integers, +, -, *, / operators
 * and empty spaces . The integer division should truncate toward zero.
 * You may assume that the given expression is always valid.
 * Some examples:
 * "3+2*2" = 7
 * " 3/2 " = 1
 * " 3+5 / 2 " = 5
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
        if (index < s.length() && (s[index] == '*' || s[index] == '/' || s[index] == '+' || s[index] == '-'))
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
            if (token->type == symbol)
                operators.push(token->symbol);
            else
            {
                if (operators.empty())
                    values.push(token->value);
                else if (operators.top() == '*' || operators.top() == '/')
                {
                    int value = values.top();
                    values.pop();
                    if (operators.top() == '*')
                        values.push(value * token->value);
                    else
                        values.push(value / token->value);
                    operators.pop();
                    Token* nextToken = getToken();
                    if (nextToken == NULL || (nextToken->type == symbol &&
                                (nextToken->symbol == '+' || nextToken->symbol == '-')))
                    {
                        if (!operators.empty() && (operators.top() == '+' || operators.top() == '-'))
                        {
                            int value1 = values.top();
                            values.pop();
                            int value2 = values.top();
                            values.pop();
                            if (operators.top() == '+')
                                values.push(value1+value2);
                            else
                                values.push(value2-value1);
                            operators.pop();
                        }
                    }
                    if (nextToken != NULL)
                        operators.push(nextToken->symbol);
                }
                else
                {
                    // if next token is '/' or '*', then push value to stack
                    Token* nextToken = getToken();
                    if (nextToken != NULL && nextToken->type == symbol &&
                            (nextToken->symbol == '*' || nextToken->symbol == '/'))
                    {
                        values.push(token->value);
                        operators.push(nextToken->symbol);
                    }
                    else
                    {
                        int value = values.top();
                        values.pop();
                        if (operators.top() == '+')
                            values.push(value + token->value);
                        else
                            values.push(value - token->value);
                        operators.pop();
                        if (nextToken != NULL)
                            operators.push(nextToken->symbol);
                        else
                            break;
                    }
                }
            }
        }

        while (!operators.empty())
        {
            int value1 = values.top();
            values.pop();
            int value2 = values.top();
            values.pop();
            if (operators.top() == '+')
                values.push(value1+value2);
            else
                values.push(value2-value1);
            operators.pop();
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
    // string str = "1*2-2/4+5*6 ";
    string str = "2*3*4";
    int result = s.calculate(str);
    cout<<result<<endl;
    return 0;
}

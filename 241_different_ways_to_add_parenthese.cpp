/*******************************************************************************
 *  @File  : 241_different_ways_to_add_parenthese.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sun 07 Aug 2016 05:16:11 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 *
 */

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:

    void generate(string input, vector<int>& values, vector<char>& operators)
    {
        int start = 0;
        while (start < input.size())
        {
            if (isdigit(input[start]))
            {
                int value = input[start] - '0';
                start++;
                while (start < input.size() && isdigit(input[start]))
                    value = (10 * value + input[start++] - '0');
                values.push_back(value);
            }
            else if (input[start] == '+' || input[start] == '-' || input[start] == '*')
            {
                operators.push_back(input[start]);
                start++;
            }
        }
    }

    set<int> compute(const vector<int>& values, const vector<char>& operators, int start, int end, bool forward=true)
    {
        set<int> result;
        if (start > end)
            return result;
        if (start == end)
        {
            result.insert(values[start]);
            return result;
        }

        // First round
        set<int> behind = compute(values, operators, start+1, end);
        for (auto num : behind)
        {
            switch (operators[start])
            {
                case '+':
                    result.insert(num + values[start]);
                    break;
                case '-':
                    if (forward)
                        result.insert(values[start] - num);
                    else
                        result.insert(num - values[start]);
                    break;
                case '*':
                    result.insert(values[start] * num);
            }
        }
        // Second round
        int comb;
        switch (operators[start])
        {
            case '+':
                comb = values[start] + values[start+1];
                break;
            case '-':
                if (forward)
                    comb = values[start] - values[start+1];
                else
                    comb = values[start+1] - values[start];
                break;
            case '*':
                comb = values[start] * values[start+1];
        }
        set<int> round2 = compute(values, operators, start+2, end);
        if (round2.size() > 0)
        {
            for (auto num : round2)
            {
                switch (operators[start+1])
                {
                    case '+':
                        result.insert(comb + num);
                        break;
                    case '-':
                        if (forward)
                            result.insert(comb - num);
                        else
                            result.insert(num - comb);
                        break;
                    case '*':
                        result.insert(comb * num);
                        break;
                }
            }
        }
        else
            result.insert(comb);
    }

    // This method can calculate all the possible result, but could not identify them.
    vector<int> diffWaysToCompute1(string input) {
        vector<int> values;
        vector<char> operators;
        generate(input, values, operators);
        
        // forward
        set<int> f = compute(values, operators, 0, values.size()-1, true);
        // backward
        reverse(values.begin(), values.end());
        reverse(operators.begin(), operators.end());
        set<int> b = compute(values, operators, 0, values.size()-1, false);

         vector<int> result(f.size() + b.size());
         set_union(f.begin(), f.end(), b.begin(), b.end(), result.begin());
        // vector<int> result(b.begin(), b.end());
        return result;
    }

    // Method from leetcode.
    vector<int> diffWaysToCompute(string input)
    {
        vector<int> result;
        for (int i = 0; i < input.length(); ++i)
        {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*')
            {
                string forward = input.substr(0, i);
                string backward = input.substr(i+1, input.length()-i-1);
                vector<int> forward_vec = diffWaysToCompute(forward);
                vector<int> backward_vec = diffWaysToCompute(backward);
                for (auto f : forward_vec)
                {
                    for (auto b : backward_vec)
                    {
                        switch (input[i])
                        {
                            case '+':
                                result.push_back(f + b);
                                break;
                            case '-':
                                result.push_back(f - b);
                                break;
                            case '*':
                                result.push_back(f * b);
                        }
                    }
                }
            }
        }
        if (result.size() == 0)
            result.push_back(atoi(input.c_str()));
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> result = s.diffWaysToCompute("2*3-4*5");
    for (auto num : result)
        cout<<num<<endl;
    return 0;
}

/*******************************************************************************
 *  @File  : 155_min_stack.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Sun 22 May 2016 11:04:43 AM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 *
 */

#include <iostream>
#include <stack>

using namespace std;

class MinStack 
{
public:
    MinStack()
    {
    }

    void push(int x)
    {
        _stack.push(x);
        if (_min.empty() || x <= _min.top())
        {
            _min.push(x);
        }
    }

    void pop()
    {
        if (!_stack.empty())
        {
            if (_stack.top() == _min.top())
            {
                _min.pop();
            }
            _stack.pop();
        }
    }
    
    int top()
    {
        if (!_stack.empty())
            return _stack.top();
        else
            return -1;
    }

    int getMin()
    {
        if (!_min.empty())
            return _min.top();
        else
            return -1;
    }

    bool empty()
    {
        return _stack.empty();
    }
private:
    stack<int> _stack;
    stack<int> _min;
};

int main()
{
    MinStack minStack;
    int nums[] = {3, 2, 7, 1, 4, 8, 1};
    for (int i = 0; i < sizeof(nums)/sizeof(int); ++i)
    {
        minStack.push(nums[i]);
        cout<<"push "<<nums[i]<<". Current top: "<<minStack.top()<<". Current min: "<<minStack.getMin()<<endl;
    }
    while (!minStack.empty())
    {
        cout<<"pop "<<minStack.top();
        minStack.pop();
        cout<<". Current min: "<<minStack.getMin()<<endl;
    }

    return 0;
}

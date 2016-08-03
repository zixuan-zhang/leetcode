/*******************************************************************************
 *  @File  : 225_implement_stack_using_queues.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Wed 03 Aug 2016 09:03:01 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Implement the following operations of a stack using queues.
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on front of the stack.
 * front() -- Get the front element.
 * empty() -- Return whether the stack is empty.
 *
 */

#include <iostream>
#include <queue>

using namespace std;

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        queue<int>* first = NULL;
        queue<int>* second = NULL;
        if (!q1.empty())
        {
            first = &q1;
            second = &q2;
        }
        else
        {
            first = &q2;
            second = &q1;
        }
        first->push(x);
    }

    // Removes the element on front of the stack.
    void pop() {
        queue<int>* first = NULL;
        queue<int>* second = NULL;
        if (!q1.empty())
        {
            first = &q1;
            second = &q2;
        }
        else
        {
            first = &q2;
            second = &q1;
        }
        while (first->size() > 1)
        {
            second->push(first->front());
            first->pop();
        }
        first->pop();
    }

    // Get the front element.
    int top() {
        int value;
        queue<int>* first = NULL;
        queue<int>* second = NULL;
        if (!q1.empty())
        {
            first = &q1;
            second = &q2;
        }
        else
        {
            first = &q2;
            second = &q1;
        }
        while (!first->empty())
        {
            if (first->size() == 1)
                value = first->front();
            second->push(first->front());
            first->pop();
        }
        return value;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty() && q2.empty();
    }

private:
    queue<int> q1;
    queue<int> q2;
};


int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    while (!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    s.push(5);
    s.push(6);
    s.pop();
    s.push(7);
    while (!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}

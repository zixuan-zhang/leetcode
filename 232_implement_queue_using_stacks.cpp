/*******************************************************************************
 *  @File  : 232_implement_queue_using_stacks.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Fri 05 Aug 2016 07:38:48 PM CST
 ******************************************************************************/

/*
 * Question:
 *
 * Implement the following operations of a queue using stacks.
 *
 * push(x) -- Push element x to the back of queue.
 * pop() -- Removes the element from in front of queue.
 * peek() -- Get the front element.
 * empty() -- Return whether the queue is empty.
 * Notes:
 * You must use only standard operations of a stack -- which means only push
 * to top, peek/pop from top, size, and is empty operations are valid.
 * Depending on your language, stack may not be supported natively. You may
 * simulate a stack by using a list or deque (double-ended queue), as long as
 * you use only standard operations of a stack.
 * You may assume that all operations are valid (for example, no pop or peek
 * operations will be called on an empty queue).
 *
 */

#include <iostream>
#include <stack>

using namespace std;

class Queue
{
public:
    void push(int x) {
        while (!out.empty())
        {
            in.push(out.top());
            out.pop();
        }
        in.push(x);
    }

    void pop(void) {
        if (!out.empty())
        {
            out.pop();
            return;
        }
        if (!in.empty())
        {
            while (in.size() > 1)
            {
                out.push(in.top());
                in.pop();
            }
            in.pop();
        }
    }

    int peek(void) {
        if (!out.empty())
            return out.top();
        while (!in.empty())
        {
            out.push(in.top());
            in.pop();
        }
        return out.top();
    }

    bool empty(void) {
        return in.empty() && out.empty();
    }

private:
    stack<int> in;
    stack<int> out;
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    
    cout<<q.peek()<<endl;
    q.push(5);
    q.push(6);
    q.push(7);
    q.pop();
    q.push(8);
    while (!q.empty())
    {
        cout<<q.peek()<<endl;
        q.pop();
    }

    return 0;
}

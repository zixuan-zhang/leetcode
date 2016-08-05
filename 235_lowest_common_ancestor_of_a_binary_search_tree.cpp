/*******************************************************************************
 *  @File  : 235_lowest_common_ancestor_of_a_binary_search_tree.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Fri 05 Aug 2016 10:37:13 PM CST
 ******************************************************************************/

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        if (!q1.empty())
        {
            queue<int>& first = q1;
            queue<int>& second = q2;
        }
        else
        {
            queue<int>& first = q2;
            queue<int>& second = q1;
        }
        first.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if (!q1.empty())
        {
            queue<int>& first = q1;
            queue<int>& second = q2;
        }
        else
        {
            queue<int>& first = q2;
            queue<int>& second = q1;
        }
        while (first.size() > 1)
        {
            second.push(first.top());
            first.pop();
        }
        first.pop();
    }

    // Get the top element.
    int top() {
        int value;
        if (!q1.empty())
        {
            queue<int>& first = q1;
            queue<int>& second = q2;
        }
        else
        {
            queue<int>& first = q2;
            queue<int>& second = q1;
        }
        while (!first.empty()
        {
            if (first.size() == 1)
                value = first.top();
            second.push(first.top());
            first.pop();
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

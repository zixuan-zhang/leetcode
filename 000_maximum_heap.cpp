/*******************************************************************************
 *  @File  : 000_maximum_heap.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : Thu 04 Aug 2016 10:57:56 PM CST
 ******************************************************************************/

#include <iostream>
#include <cassert>

using namespace std;

class PriorityQueue 
{
public:
    PriorityQueue(int cap) : capacity(cap), size(0)
    {
        assert(cap > 0);
        queue = new int[this->capacity];
    }

    ~PriorityQueue() {};

    bool insert(int x)
    {
        if (size >= capacity)
            return false;
        int index = size;
        while (index > 0 && queue[(index-1) / 2] < x)
        {
            queue[index] = queue[(index-1)/2];
            index = (index-1) / 2;
        }
        queue[index] = x;
        size++;
    }

    bool front(int& x)
    {
        if (size == 0)
            return false;
        x = queue[0];
        int index = 0;
        int _max = -1;
        while (true)
        {
            if ( 2 * index + 1 < size)
                _max = 2 * index + 1;
            else
                break;
            if ( 2 * index + 2 < size && queue[2*index+1] < queue[2*index+2])
                _max = 2 * index + 2;
            if (queue[_max] < queue[size-1])
                break;
            queue[index] = queue[_max];
            index = _max;
        }
        queue[index] = queue[--size];
        return true;
    }

    bool empty()
    {
        return size == 0;
    }

    void show()
    {
        for (int i = 0; i < size; ++i)
            cout<<queue[i]<<" ";
        cout<<endl;
    }

private:
    int size;
    int capacity;
    int* queue;
};

int main()
{
    PriorityQueue queue(50);
    for (int i = 1; i < 100; ++i)
    {
        queue.insert(i);
    }
    //queue.show();
    //return 0;
    while (!queue.empty())
    {
        int x;
        queue.front(x);
        cout<<x<<endl;
    }

    return 0;
}

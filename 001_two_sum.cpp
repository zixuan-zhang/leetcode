
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    /*
     * 使用map，两次循环就可以了。时间复杂度是O(n)。以空间换时间。
     * 当然还有其他的方法
     */
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        vector<int> result;
        result.resize(2);
        map<int, int> m;
        for (int i = 0; i < numbers.size(); ++i)
        {
            m[numbers[i]] = i + 1;
        }

        for (int i = 0; i < numbers.size(); ++i)
        {
            int temp = target - numbers[i];
            if (m.find(temp) != m.end())
            {
                if ( (i+1) == m[temp]) //过滤target是某个数的两倍情况
                    continue;
                result[0] = (i+1) < m[temp] ? (i+1) : m[temp];
                result[1] = (i+1) > m[temp] ? (i+1) : m[temp];
                break;
            }
        }
        return result;
    }
};

int main()
{
    int num[] = {2, 7, 11, 15};
    vector<int> numbers;
    for (int i = 0; i < 4; ++i)
    {
        numbers.push_back(num[i]);
    }
    Solution s;
    vector<int> result = s.twoSum(numbers, 18);
    for (int i = 0; i < result.size(); ++i)
    {
        cout<<result[i]<<" ";
    }
    return 0;
}

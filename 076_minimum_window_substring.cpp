/*******************************************************************************
 *  @File  : 76_minimum_window_substring.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2016年03月25日 星期五 19时54分23秒
 ******************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;


class Solution
{
public:
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        for(auto c: t)
            map[c]++;
        int counter=t.size(), begin=0, end=0, d=INT_MAX, head=0;
        while(end<s.size()){
            if(map[s[end++]]-->0)
                counter--; //in t
            while(counter==0){ //valid
                if(end-begin<d)
                    d=end-(head=begin);
                if(map[s[begin++]]++==0)
                    counter++;  //make it invalid
            }  
        }
        return d==INT_MAX? "":s.substr(head, d);
    }
};

int main()
{
    Solution s;
    string res = s.minWindow("ADOBECODEBANC", "ABC");
    cout<<res<<endl;
    return 0;
}

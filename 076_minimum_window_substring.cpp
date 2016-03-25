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
    /*
     * Bad Method:
     */
    string minWindow1(string s, string t) {
        if (s.length() == 0 || t.length() == 0)
            return "";
        unordered_map<char, vector<int> > char2indexes;
        for (int i = 0; i < t.length(); ++i)
        {
             unordered_map<char, vector<int> >::iterator it = char2indexes.find(t[i]);
             if (it == char2indexes.end())
             {
                 vector<int> indexes(1,-1);
                 char2indexes[t[i]] = indexes;
             }
             else
             {
                 it->second.push_back(-1);
             }
        }
        vector<int> lastIndex(s.length(), -1);
        for (int i = 0; i < s.length(); ++i)
        {
            if (t.find(s[i]) != -1)
            {
                unordered_map<char, vector<int> >::iterator it = char2indexes.find(s[i]);
                int min_index = -1;
                int min_value = INT_MAX;
                for (int j = 0; j < it->second.size(); ++j)
                {
                    if (min_value > it->second[j])
                    {
                        min_value = it->second[j];
                        min_index = j;
                    }
                }
                it->second[min_index] = i; 
            }
            int index = INT_MAX;
            for (unordered_map<char,vector<int> >::iterator it = char2indexes.begin(); it != char2indexes.end(); ++it)
            {
                for (int i = 0; i < it->second.size(); ++i)
                {
                    index = min(it->second[i], index);
                }
            }
            if (-1 != index)
                lastIndex[i] = (i-index+1);
            cout<<lastIndex[i]<<" ";
        }
        int _min = INT_MAX;
        int index = -1;
        for (int i = 0; i < lastIndex.size(); ++i)
        {
            if (lastIndex[i] != -1)
            {
                if (_min > lastIndex[i])
                {
                    _min = lastIndex[i];
                    index = i;
                }
            }
        }
        if (-1 == index)
            return "";
        return s.substr(index-_min+1, _min);
    }
    
    /*
     * Good Method
     */
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
